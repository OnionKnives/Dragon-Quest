#pragma once
#include <SDL.h>

#include "texture.h"

class Tile {
public:
	Tile(Texture* newTexture);
	void render();
	void setDestinationPoint(SDL_Point p);
	bool collision();
	void setImpassible();
	
	int ID = 0;

private:
	Texture* texture;
	bool collidable = false;
};