// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef LoopingLeni_H_
#define LoopingLeni_H_
//#include "Arduino.h"
//add your includes for the project LoopingLeni here

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project Test here
void scrollDisplays();
void readInputs();
void processInputs();
void sendData();
void setMultiDisplayText(const char text, int size);
void tick();
void disableButtons();
void enableButtons();
void setNormalSpeed();
void setTurboSpeed();
void updatePlayerStatus();
void updateTurboStatus();
void stopMotor();
void startGame();
void startRound();
void randomSpeed();
void randomDirection();
void startMotor();
void checkChips();
void looserFound(int p);
void scheduleRandomDirectionSpeed();
void enableExtraScrollTimer();
void disableExtraScrollTimer();
//Do not add code below this line
#endif /* LoopingLeni_H_ */
