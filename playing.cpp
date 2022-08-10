#include "npcs.h"
#include "music.h"
#include "camera.h"
#include "player.h"
#include "render.h"
#include "gameMap.h"
#include "playing.h"

SDL_Point lastLoc;

void initializePlayState() {
	playCastleMusic();
	initializePlayer();
	setPlayerPos({ 14, 14 });
	lastLoc = {getXPos(), getYPos()};
	switchMap(1);
}

void shutdownPlayState() {

}

void updatePlayState() {
	updatePlayer();
	updateCamera();

	if (lastLoc.x != getXPos() || lastLoc.y != getYPos()) {
		if (getMapID() != 0) {
			if (getXPos() == 0 || getYPos() == 0 ||
				getXPos() == 31 * tileSize() || getYPos() == 31 * tileSize()) {
				switch (getMapID()) {
				case 1:
					setPlayerPos({ 211, 60 });
					break;
				case 2:
					setPlayerPos({ 213, 61 });
					break;
				default:
					setPlayerPos({ 211, 60 });
					break;
				}
				switchMap(0);
				playOverworldMusic();
			}
		}
		else {
			if (getXPos() == 211 * tileSize() && getYPos() == 60 * tileSize()) {
				setPlayerPos({15, 28});
				switchMap(1);
				playCastleMusic();
			}

			else if (getXPos() == 213 * tileSize() && getYPos() == 61 * tileSize()) {
				setPlayerPos({1, 15});
				switchMap(2);
				playVillageMusic();
			}
		}

		lastLoc = { getXPos(), getYPos() };
	}

	updateNPCs();
}

void renderPlayState() {
	renderMap();
	renderNPCs();
	renderPlayer();
}

State checkPlayState() {
	return State::Playing;
}
