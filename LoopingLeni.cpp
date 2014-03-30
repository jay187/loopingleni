//
// Version 20140330.1525
//

#include "LoopingLeni.h"

#include "Arduino.h"

#include "MatrixDriver.h"

#include "LoopingLouie.h"
#include "LoopingLouieStruct.h"
#include "QueueArray.h"

#include "SimpleTimer.h"

#define DISPLAY_COUNT 8
#define DISPLAY_COLUMNS 8
#define DIRECTION_RANDOM 80
#define RANDOM_STOP 95

#define GAME_BOOT 0
#define GAME_ACTIVE 1
#define GAME_CHECK_PLAYERS 2
#define GAME_STOPPED 3
#define GAME_IDLE 4

#define MOTOR_FORWARD 2
#define MOTOR_BACKWARD 1

// SET PINS
const uint8_t CLOCK_PIN = 10;
const uint8_t DATA_PIN = 9;
const uint8_t STROBE_PIN = 8;
const uint8_t INPUT_PIN = 7;

const uint8_t SPEED_PIN = 11;
const uint8_t DIRECTION_PIN_1 = 12;
const uint8_t DIRECTION_PIN_2 = 13;

const uint8_t MIN_SPEED = 30;
const uint8_t NORMAL_SPEED = 50;
const uint8_t TURBO_SPEED = 90;

const unsigned int TURBO_DURATION = 1000;
const unsigned int CHIP_LOST_DELAY = 750;
const unsigned int START_ROUND_DELAY = 3250;

const uint8_t CHIP_ACTIVE = 1;
const uint8_t CHIP_PENDING = 2;
const uint8_t CHIP_LOST = 3;
const uint8_t CHIP_INACTIVE = 4;


char BOOT_TEXT[] = " <<LOOPING LENI>>";
char GO_TEXT[] = " GO! GO! GO! ";
char TURBO_TEXT[] = " !TURBO! ";
char START_ROUND_TEXT[] = " BLAUER BUTTON ";

uint8_t motor_speed = 0;
uint8_t motor_direction = MOTOR_FORWARD;

uint8_t game_state = GAME_BOOT;

uint8_t random_speed_timer;
uint8_t scroll_double_timer = 0;
uint8_t turbo_speed_timer = 0;
uint8_t random_direction_timer = 0;
uint8_t motor_random = 0;
boolean one_player_active = false;

volatile boolean BUTTONS_ENABLED = false;
volatile boolean TURBO_ACTIVE = false;

//byte player_inputs[DISPLAY_COUNT] = { 0 };

QueueArray<int> chip_pending;
QueueArray<int> game_lost;


int player_status[DISPLAY_COUNT] = { CHIP_INACTIVE };

// SET PROG VARS
MatrixDriver displays[DISPLAY_COUNT];

// GAME
LoopingLouie game(DISPLAY_COUNT);

// CHIP CHECKER
long chip_check[DISPLAY_COUNT] = { 0 };

// SCHEDULER
SimpleTimer scheduler;

void setup() {
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(STROBE_PIN, OUTPUT);
  pinMode(SPEED_PIN, OUTPUT);
  pinMode(DIRECTION_PIN_1, OUTPUT);
  pinMode(DIRECTION_PIN_2, OUTPUT);
  analogWrite(SPEED_PIN, 0);

  pinMode(INPUT_PIN, INPUT);

  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].setPosition(i);
    displays[i].setMultiScrolling(BOOT_TEXT, sizeof(BOOT_TEXT));
  }
  digitalWrite(DIRECTION_PIN_1, HIGH);
  digitalWrite(DIRECTION_PIN_2, LOW);


  scheduler.setInterval(35, scrollDisplays);
  scheduler.setInterval(300, updateTurboStatus);
  scheduler.setTimeout(9750, startGame);
  //scheduler.setInterval(300, updatePlayerStatus);

  random_speed_timer = scheduler.setInterval(2000, randomSpeed);
  random_direction_timer = scheduler.setInterval(3000, randomDirection);
}

void startGame(){
  enableButtons();
  updatePlayerStatus();
//  setInfiniteMultiDisplayText(START_ROUND_TEXT, sizeof(START_ROUND_TEXT));
  game_state = GAME_IDLE;
}

void updateTurboStatus() {
  game.updateTurboStates();
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].setTurbo(game.getTurbo(i));
  }
}

void updatePlayerStatus() {
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].enablePlayerStatus();
    displays[i].setPlayerStatus(game.getLost(i), game.getTurbo(i));
    //displays[i].setPlayerStatus(motor_direction, game.getTurbo(i));
  }
}

void setMultiDisplayText(char *text, int size) {
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].setSingleScrolling(text, size, 1);
  }
}

void setInfiniteMultiDisplayText(char *text, int size){
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].setMultiScrolling(text, size);
  }
}

void scrollDisplays() {
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].scroll();
  }
}

void loop() {
  scheduler.run();
  readInputs();
  sendData();
}

void randomSpeed(){
	motor_speed = random(MIN_SPEED, NORMAL_SPEED);
  startMotor();
}

void scheduleRandomDirectionSpeed(){
  //MOTOR SCHEDULE
  scheduler.enable(random_speed_timer);
  scheduler.enable(random_direction_timer);
}

void randomDirection(){
  //motor_random = random(0,100);
  if (motor_direction == MOTOR_FORWARD && random(0,100) > RANDOM_STOP){
    motor_direction = MOTOR_FORWARD;
    motor_speed = 0;
    scheduler.setTimeout(random(1000, 2500), randomDirection);
  }
  else if (motor_direction == MOTOR_FORWARD && random(0,100) > DIRECTION_RANDOM){
    motor_direction = MOTOR_BACKWARD;
    scheduler.setTimeout(random(1000, 2500), randomDirection);
  }
  else{
    motor_direction = MOTOR_FORWARD;
  }
  startMotor();
}

void startMotor(){
  if (game_state == GAME_ACTIVE){
    if (motor_direction == MOTOR_FORWARD){
      digitalWrite(DIRECTION_PIN_1, HIGH);
      digitalWrite(DIRECTION_PIN_2, LOW);
    }
    else if(motor_direction == MOTOR_BACKWARD){
      digitalWrite(DIRECTION_PIN_1, LOW);
      digitalWrite(DIRECTION_PIN_2, HIGH);
    }
    if(TURBO_ACTIVE){
      analogWrite(SPEED_PIN, TURBO_SPEED);
    }
    else{
      analogWrite(SPEED_PIN, motor_speed);
    }

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
}

void disableButtons() {
  BUTTONS_ENABLED = false;
}

void enableButtons() {
  updatePlayerStatus();
  BUTTONS_ENABLED = true;
}

void setNormalSpeed() {
  TURBO_ACTIVE = false;
  disableExtraScrollTimer();
  motor_speed = NORMAL_SPEED;
  scheduleRandomDirectionSpeed();
  startMotor();
}

void setTurboSpeed() {
  enableExtraScrollTimer();
  scheduler.disable(random_speed_timer);
  scheduler.disable(random_direction_timer);
  analogWrite(SPEED_PIN, TURBO_SPEED);
}

void stopMotor() {
  analogWrite(SPEED_PIN, 0);
}

void enableExtraScrollTimer(){
  //scroll_double_timer = scheduler.setInterval(70, scrollDisplays);
}

void disableExtraScrollTimer(){
 // if(scroll_double_timer > 0){
    //scheduler.stop(scroll_double_timer );
 // }
}

void checkChips() {
  int p = chip_pending.pop();
  player_status[p] = CHIP_LOST;
  //displays[p].setPlayerStatus(game.getLost(p), game.getTurbo(p));
  if (game_state == GAME_ACTIVE){
    updatePlayerStatus();
  }
}

void startRound(){
  game_state = GAME_ACTIVE;
  TURBO_ACTIVE = false;
  disableExtraScrollTimer();
  setNormalSpeed();
  updatePlayerStatus();
}

void looserFound(int p) {
  game_state = GAME_STOPPED;
  disableButtons();
  stopMotor();
  game.raiseLost(p);
  game.resetPlayers();
  //updatePlayerStatus();
  char text[11] = " LOOSER #";
  text[9] = (char) p + 49;
  text[10] = ' ';
  //setMultiDisplayText(text, sizeof(text));
  setInfiniteMultiDisplayText(text, sizeof(text));
  scheduler.setTimeout(8500, startGame);
  one_player_active = false;
  player_status[p] = CHIP_ACTIVE;
}


void readInputs() {
//  if (!BUTTONS_ENABLED)
//    return;
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
    if (BUTTONS_ENABLED && one_player_active && game_state == GAME_IDLE && (~player_input & B00000100)) {
      //BLUE BUTTON
      game_state = GAME_CHECK_PLAYERS;
      setMultiDisplayText(GO_TEXT, sizeof(GO_TEXT));
      scheduler.setTimeout(START_ROUND_DELAY, startRound);
      enableExtraScrollTimer();
      return;
    }
    else if (BUTTONS_ENABLED && game_state == GAME_ACTIVE && player_status[p] == CHIP_ACTIVE && (~player_input & B00000010)) {
      //TURBO
      if (motor_direction == MOTOR_FORWARD && game.useTurbo(p)) {
        TURBO_ACTIVE = true;
        disableButtons();
        setTurboSpeed();
        scheduler.setTimeout(TURBO_DURATION, enableButtons);
        scheduler.setTimeout(TURBO_DURATION, setNormalSpeed);
        displays[p].setSingleScrolling(TURBO_TEXT, sizeof(TURBO_TEXT), 1);
        return;
      }
    }
    else if (game_state == GAME_ACTIVE && player_status[p] != CHIP_INACTIVE && (player_input & B00000001)) {
      //LICHTSCHRANKE
      if (player_status[p] != CHIP_PENDING){
        if (player_status[p] == CHIP_ACTIVE) {
          player_status[p] = CHIP_PENDING;
          displays[p].setStaticText('~');
          chip_pending.push(p);
          scheduler.setTimeout(CHIP_LOST_DELAY, checkChips);
          return;
        }
        else if (game_state == GAME_ACTIVE && player_status[p] == CHIP_LOST) {
          looserFound(p);
          return;
        }
      }
    }
    else if (game_state == GAME_ACTIVE && (~player_input & B00000001)) {
        player_status[p] = CHIP_ACTIVE;
    }
    else if (game_state == GAME_CHECK_PLAYERS && (~player_input & B00000001)){
      player_status[p] = CHIP_ACTIVE;
    }
    else if (game_state == GAME_IDLE && (~player_input & B00000001)){
      player_status[p] = CHIP_ACTIVE;
      one_player_active = true;
    }
    else if (game_state == GAME_CHECK_PLAYERS && (player_input & B00000001)){
      player_status[p] = CHIP_INACTIVE;
    }
  }
}
