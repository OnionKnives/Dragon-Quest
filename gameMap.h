#pragma once
#include <SDL.h>

void loadMaps();
void renderMap();
bool mapCollision(SDL_Point pos);
int tileSize();

int getMapID();
int getStandingTileID(SDL_Point pos);

void switchMap(int mapID);