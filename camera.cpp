#include <SDL.h>

#include "camera.h"
#include "player.h"
#include "render.h"
#include "gameMap.h"

SDL_Rect camera;

void initializeCamera() {
	camera.x = 0;
	camera.y = 0;
	camera.w = screenWidth();
	camera.h = screenHeight();
}

SDL_Rect* getCamera() {
	return &camera;
}

void updateCamera() {
	camera.x = (getXPos() + 20) - screenWidth() / 2;
	camera.y = (getYPos() + 20) - screenHeight() / 2;

	int mapSize = getMapID() == 0 ? 255 : 32;

	if (camera.x < 0) {
		camera.x = 0;
	}
	if (camera.y < 0) {
		camera.y = 0;
	}
	if (camera.x > 40 * mapSize - camera.w) {
		camera.x = 40 * mapSize - camera.w;
	}
	if (camera.y > 40 * mapSize - camera.h) {
		camera.y = 40 * mapSize - camera.h;
	}
}
