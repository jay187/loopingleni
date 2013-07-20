//
// Version 20130720.1600
//

#include "LoopingLeni.h"

#include "Arduino.h"

#include "MatrixDriver.h"

#include "LoopingLouie.h"
#include "LoopingLouieStruct.h"
#include "QueueArray.h"

//#include "looper.h"
#include "SimpleTimer.h"

#define DISPLAY_COUNT 4
#define DISPLAY_COLUMNS 8
#define DIRECTION_RANDOM 80
#define RANDOM_STOP 70

#define GAME_BOOT 0
#define GAME_ACTIVE 1
#define GAME_CHECK_PLAYERS 2
#define GAME_STOPPED 3

// SET PINS
unsigned int CLOCK_PIN = 10;
unsigned int DATA_PIN = 9;
unsigned int STROBE_PIN = 8;
unsigned int INPUT_PIN = 7;

unsigned int SPEED_PIN = 11;
unsigned int DIRECTION_PIN_1 = 12;
unsigned int DIRECTION_PIN_2 = 13;

int NORMAL_SPEED = 200;
int TURBO_SPEED = 255;

int motor_speed = 0;
int motor_direction = 1;

int timer_count = 0;

int TURBO_DURATION = 1500;

volatile boolean BUTTONS_ENABLED = false;

int CHIP_LOST_DELAY = 750;

int game_state = GAME_BOOT;

int random_speed_timer;
int random_direction_timer;

QueueArray<int> chip_pending;
QueueArray<int> game_lost;

int CHIP_ACTIVE = 1;
int CHIP_PENDING = 2;
int CHIP_LOST = 3;
int CHIP_INACTIVE = 4;

int player_status[DISPLAY_COUNT] = { CHIP_INACTIVE };

// SET PROG VARS
MatrixDriver displays[DISPLAY_COUNT];

// GAME
LoopingLouie game(DISPLAY_COUNT);

// CHIP CHECKER
long chip_check[DISPLAY_COUNT] = { 0 };

// SCHEDULER
//looper scheduler;
SimpleTimer scheduler;

void setup() {
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(STROBE_PIN, OUTPUT);
  pinMode(SPEED_PIN, OUTPUT);
  pinMode(DIRECTION_PIN_1, OUTPUT);
  pinMode(DIRECTION_PIN_2, OUTPUT);

  pinMode(INPUT_PIN, INPUT);

  char text[] = " <<LOOPING LENI>> Let's get ready to drink!   ";

  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].setPosition(i);
    displays[i].setMultiScrolling(text, sizeof(text));
  }
  analogWrite(SPEED_PIN, 0);
  digitalWrite(DIRECTION_PIN_1, HIGH);
  digitalWrite(DIRECTION_PIN_2, LOW);


  scheduler.setInterval(30, scrollDisplays);
  scheduler.setInterval(250, updateTurboStatus);
  scheduler.setTimeout(21000, startGame);

  //MOTOR SCHEDULE
  random_speed_timer = scheduler.setInterval(2000, randomSpeed);
  random_direction_timer = scheduler.setInterval(3000, randomDirection);
}

void startGame(){
  enableButtons();
  updatePlayerStatus();
//  game_state = GAME_ACTIVE;
}

void updateTurboStatus() {
  game.updateTurboStates();
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].setTurbo(game.getTurbo(i));
  }
}

void updatePlayerStatus() {
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].setPlayerStatus(game.getLost(i), game.getTurbo(i));
  }
}

void setMultiDisplayText(char *text, int size) {
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].setSingleScrolling(text, size, 1);
//    displays[i].setMultiScrolling(text);
  }
}

void scrollDisplays() {
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].scroll();
  }
}

void loop() {
//  scheduler.scheduler();
  scheduler.run();
  sendData();
  if (timer_count == 5) {
    readInputs();
    timer_count = 0;
  }
  timer_count++;
}

void randomSpeed(){
  motor_speed = random(120, 220);
  startMotor();
}

void randomDirection(){
  if (motor_direction == 1 && random(0, 100) > DIRECTION_RANDOM){
    motor_direction = -1;
    scheduler.setTimeout(random(1000, 2500), randomDirection);
  }
  else if (motor_direction == 1 && random(0, 100) > RANDOM_STOP){
    motor_direction = 1;
    motor_speed = 0;
  }
  else{
    motor_direction = 1;
  }
  startMotor();
}

void startMotor(){
  if (game_state == GAME_ACTIVE){
    if (motor_direction == 1){
      digitalWrite(DIRECTION_PIN_1, HIGH);
      digitalWrite(DIRECTION_PIN_2, LOW);
    }
    else if(motor_direction == -1){
      digitalWrite(DIRECTION_PIN_1, LOW);
      digitalWrite(DIRECTION_PIN_2, HIGH);
    }
    analogWrite(SPEED_PIN, motor_speed);
  }
}

void sendData() {
  for (int i = 0; i < DISPLAY_COLUMNS; i++) {
    // set all low
    digitalWrite(CLOCK_PIN, LOW);
    digitalWrite(DATA_PIN, LOW);
    digitalWrite(STROBE_PIN, LOW);

    for (int j = DISPLAY_COUNT - 1; j >= 0; j--) {
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, (1 << i));
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, displays[j].getColumn(i));
    }
    // send strobe
    digitalWrite(STROBE_PIN, HIGH);
  }
//  readInputs();
}

void disableButtons() {
  BUTTONS_ENABLED = false;
}

void enableButtons() {
  updatePlayerStatus();
  BUTTONS_ENABLED = true;
}

void setNormalSpeed() {
  motor_speed = NORMAL_SPEED;
  startMotor();
  scheduler.enable(random_speed_timer);
  scheduler.enable(random_direction_timer);
}

void setTurboSpeed() {
  scheduler.disable(random_speed_timer);
  scheduler.disable(random_direction_timer);
  analogWrite(SPEED_PIN, TURBO_SPEED);
}

void stopMotor() {
  analogWrite(SPEED_PIN, 0);
}

void checkChips() {
  int p = chip_pending.pop();
  player_status[p] = CHIP_LOST;
  displays[p].setPlayerStatus(game.getLost(p), game.getTurbo(p));
}

void startRound(){
  game_state = GAME_ACTIVE;
  setNormalSpeed();
}

void looserFound(int p) {
  game_state = GAME_STOPPED;
  disableButtons();
  player_status[p] = CHIP_ACTIVE;
  stopMotor();
  game.raiseLost(p);
  game.resetPlayers();
  updatePlayerStatus();
  char text[10] = "LOOSER #";
  text[8] = (char) p + 49;
  text[9] = ' ';
  setMultiDisplayText(text, sizeof(text));
  scheduler.setTimeout(5000, enableButtons);
}

void readInputs() {
  if (!BUTTONS_ENABLED)
    return;
  // send strobe
  digitalWrite(STROBE_PIN, HIGH);
  digitalWrite(STROBE_PIN, LOW);

  for (int p = 0; p < DISPLAY_COUNT; p++) {
    byte player_input = 0;
    for (int b = 0; b < 8; b++) {
      if (digitalRead(INPUT_PIN)) {
        player_input = player_input | (1 << b);
      }
      digitalWrite(CLOCK_PIN, HIGH);
      digitalWrite(CLOCK_PIN, LOW);
    }

    if ((~player_input & B00000010) &&  player_status[p] == CHIP_ACTIVE && game_state == GAME_ACTIVE) {
      //TURBO
      if (game.useTurbo(p)) {
        disableButtons();
        setTurboSpeed();
        scheduler.setTimeout(TURBO_DURATION, enableButtons);
        scheduler.setTimeout(TURBO_DURATION, setNormalSpeed);
        char text[] = " !TURBO! ";
        displays[p].setSingleScrolling(text, sizeof(text), 1);
      }
      return;
    }
    else if (~player_input & B00000100) {
      //BLUE BUTTON
      game_state = GAME_CHECK_PLAYERS;
      char text[] = " GO! GO! GO! ";
      setMultiDisplayText(text, sizeof(text));
      scheduler.setTimeout(2500, startRound);
    }
    else if ((player_input & B00000001) && game_state == GAME_ACTIVE) {
      //LICHTSCHRANKE
      if (player_status[p] != CHIP_PENDING){
        if (player_status[p] == CHIP_ACTIVE) {
          displays[p].setStaticText('~');
          chip_pending.push(p);
          player_status[p] = CHIP_PENDING;
          scheduler.setTimeout(CHIP_LOST_DELAY, checkChips);
        }
        else if (player_status[p] == CHIP_LOST) {
          looserFound(p);
        }
      }
    }
    else if ((~player_input & B00000001) && game_state == GAME_ACTIVE) {
        player_status[p] = CHIP_ACTIVE;
    }
    else if ((~player_input & B00000001) && game_state == GAME_CHECK_PLAYERS){
      player_status[p] = CHIP_ACTIVE;
    }
    else if ((player_input & B00000001) && game_state == GAME_CHECK_PLAYERS){
      player_status[p] = CHIP_INACTIVE;
    }
  }
}
