#include "LoopingLeni.h"

#include "Arduino.h"
#include "LoopingLouie.h"
#include "LoopingLouieStruct.h"

#include "MatrixDriver.h"
#include "TimerOne.h"

#define DISPLAY_COUNT 4
#define DISPLAY_COLUMNS 8

// SET PINS
unsigned int CLOCK_PIN = 10;
unsigned int DATA_PIN = 9;
unsigned int STROBE_PIN = 8;
unsigned int INPUT_PIN = 7;

unsigned int SPEED_PIN = 11;
unsigned int DIRECTION_PIN_1 = 12;
unsigned int DIRECTION_PIN_2 = 13;

// SET PROG VARS
MatrixDriver displays[DISPLAY_COUNT + 1];

// GAME
LoopingLouie game;

//CREATE TIMER


void setup() {
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(STROBE_PIN, OUTPUT);
  pinMode(SPEED_PIN, OUTPUT);
  pinMode(DIRECTION_PIN_1, OUTPUT);
  pinMode(DIRECTION_PIN_2, OUTPUT);

  pinMode(INPUT_PIN, INPUT);

  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].setPosition(i);
    displays[i].clearDisplay();
//    displays[i].setSingleScrolling("!TURBO!", 10  );
//    displays[i].setStaticText('A');
//    displays[i].setPlayerStatus((i+1)*10, i*20);
//    displays[i].setStaticNumber(i);
//    displays[i].showPosition();
    displays[i].setMultiScrolling("<<LOOPING LENI>> Let's get ready to drink!");
  }
  digitalWrite(DIRECTION_PIN_1, HIGH);
  digitalWrite(DIRECTION_PIN_2, LOW);
  analogWrite(SPEED_PIN, 0);
}

void startMultiScrolling(){
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].setMultiScrolling("<<LOOPING LENI>> Let's get ready to drink!");
  }
}

void scrollDisplays() {
  for (int i = 0; i < DISPLAY_COUNT; i++) {
    displays[i].scroll();
  }
}

void loop() {
  sendData();
}

void sendData() {

  for (int i = 0; i < DISPLAY_COLUMNS; i++) {
    // set all low
    digitalWrite(CLOCK_PIN, LOW);
    digitalWrite(DATA_PIN, LOW);
    digitalWrite(STROBE_PIN, LOW);

    for (int j = 0; j < DISPLAY_COUNT; j++) {
//      Serial.print("Display ");
//      Serial.print(j);
//      Serial.print(" -> ");
//      Serial.println(displays[j].getColumn(i), BIN);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, (1 << i));
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, displays[j].getColumn(i));
    }
    // send strobe
    digitalWrite(STROBE_PIN, HIGH);
  }
//  readInputs();

}

void readInputs() {
  // send strobe
  digitalWrite(STROBE_PIN, HIGH);
  digitalWrite(STROBE_PIN, LOW);

  for (int p = DISPLAY_COUNT - 1; p >= 0; p--) {
    byte player_input = 0;
    for (int b = 0; b < 8; b++) {
      if (digitalRead(INPUT_PIN)) {
        player_input = player_input | (1 << b);
      }
      digitalWrite(CLOCK_PIN, HIGH);
      digitalWrite(CLOCK_PIN, LOW);
    }

    if (~player_input & B00000010) {
      //TURBO
//        displays[p].setStaticText('R');
//        displays[p].setSingleScrolling(" !TURBO!  ", 1);
      analogWrite(SPEED_PIN, 255);
    } else if (~player_input & B00000100) {
      //BLUE BUTTON
//        displays[p].setStaticText('B');
      analogWrite(SPEED_PIN, 100);
    } else if (player_input & B00000001) {
      //LICHTSCHRANKE
//        displays[p].setSingleScrolling(" LOOSER ", 1);
    } else {
//         analogWrite(SPEED_PIN, 100);
//         displays[p].setStaticText(' ');
    }
  }
}
