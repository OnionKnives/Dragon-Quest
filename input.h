#pragma once

#include <SDL.h>

enum class MouseState {
	None, Down, Up
};

void input();
bool running();
void shutdown();
bool keyPressed(int key);
MouseState mouseClick(Uint8 key);
SDL_Point* mousePosition();
bool newCharInput();
char getTextInputChar();