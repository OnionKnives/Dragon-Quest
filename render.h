#pragma once
#include <SDL.h>

#include "texture.h"

void initializeGraphics();
void shutdownGraphics();

int screenWidth();
int screenHeight();

SDL_Renderer* getRenderer();