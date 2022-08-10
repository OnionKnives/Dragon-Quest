#include <SDL.h>
#include <vector>

#include "npcs.h"
#include "gameMap.h"
#include "dragonWarrior_Sprites.h"

using namespace std;

struct NPC {
	NPC();

	SDL_Point loc = { 14 * tileSize(), 12 * tileSize() };
	int mapID = 0;
	Sprite* sprite = Hero_Princess();
} king;

NPC::NPC() {
	sprite->setPoint(loc);
}

void renderNPCs() {
	king.sprite->render();
}

void updateNPCs() {
	king.sprite->update();
}
