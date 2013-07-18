// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef LoopingLeni_H_
#define LoopingLeni_H_
#include "Arduino.h"
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
void sendData();
void startMultiScrolling();
//Do not add code below this line
#endif /* LoopingLeni_H_ */
