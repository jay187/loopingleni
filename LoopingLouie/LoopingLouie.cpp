/*
 LoopingLouie.h - Looping Louie game library.
 Created by Jens Heidrich 03/17/2013.
 */
#include "Arduino.h"
#include "LoopingLouieStruct.h"
#include "LoopingLouie.h"

const double turbo_reload = 10000;
const int MAX_CHIPS = 3;

//Player players[8];

LoopingLouie::LoopingLouie(int player_count) {
  this->player_count = player_count;
	for (int i = 0; i < player_count; i++) {
		players[i] = (Player ) { false, 0, 100, millis(), 3, false};
	}
}

void LoopingLouie::updateTurboStates() {
	long now = millis();
	for (int i = 0; i < 8; i++) {
		if (this->players[i].turbo_load < 100) {
			long diff = now - this->players[i].last_turbo;
			if (diff > turbo_reload) {
				this->players[i].turbo_load = 100;
			} else {
				this->players[i].turbo_load = ceil((diff / turbo_reload * 100));
			}
		}
	}
}

boolean LoopingLouie::useTurbo(int id) {
	if (this->players[id].turbo_load == 100) {
		this->players[id].last_turbo = millis();
		this->players[id].turbo_load = 0;
		return true;
	}
	return false;
}

int LoopingLouie::getTurbo(int id) {
	return this->players[id].turbo_load;
}

int LoopingLouie::getLost(int id) {
	return this->players[id].lost;
}

void LoopingLouie::lostChip(int id) {
	this->players[id].chip_count--;
	this->players[id].pending_chip = true;
}

void LoopingLouie::resetPlayers() {
  for (int i = 0; i < this->player_count; i++) {
    this->players[i].turbo_load = 100;
  }
}

boolean LoopingLouie::hasLost(int id) {
	return this->players[id].chip_count == 0;
}

boolean LoopingLouie::hasPendingChip(int id) {
	return this->players[id].pending_chip;
}

void LoopingLouie::activatePlayer(int id) {
	this->players[id].active = true;
}

void LoopingLouie::deactivatePlayer(int id) {
	this->players[id].active = false;
}

void LoopingLouie::raiseLost(int id) {
	this->players[id].lost++;
}

void LoopingLouie::setLost(int id, int lost) {
	this->players[id].lost = lost;
}
