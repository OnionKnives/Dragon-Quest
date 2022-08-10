#pragma once
#include <SDL.h>

#include "texture.h"

enum struct Face {
	Up, Down, Left, Right
};

class Sprite {
public:
	Sprite();
	Sprite(Texture* spriteTexture);

	void update();
	void render();
	void face(Face direction);
	void setClipRect(SDL_Rect rect);
	void setPoint(SDL_Point& point);

private:
	Texture* texture;
	Face facing = Face::Down;
	SDL_Rect spriteOrigin = { 0, 0, 16, 16 };
	SDL_Rect clippingRect = { 0, 0, 16, 16 };
	SDL_Point renderPoint = { 0, 0 };

	int spriteSize = 16;
};