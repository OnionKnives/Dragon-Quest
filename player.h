#pragma once
#include "sprite.h"

void initializePlayer();
void updatePlayer();
void renderPlayer();

int getXPos();
int getYPos();

void setPlayerPos(SDL_Point pos);