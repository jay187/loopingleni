/*
 LoopingLouie.h - Looping Louie game library.
 Created by Jens Heidrich 03/17/2013.
 */
#ifndef LoopingLouie_h
#define LoopingLouie_h

#include "Arduino.h"
#include "LoopingLouieStruct.h"

class LoopingLouie {
public:
	LoopingLouie(int player_count);
	int player_count;
	Player players[8];
	void updateTurboStates();
	boolean useTurbo(int id);
	int getTurbo(int id);
	int getLost(int id);
	void activatePlayer(int id);
	void deactivatePlayer(int id);
	void raiseLost(int id);
	void setLost(int id, int lost);
	void lostChip(int id);
	void resetPlayers();
	boolean hasLost(int id);
	boolean hasPendingChip(int id);
};
#endif
