#include "tiles.h"

Tile::Tile(Texture* newTexture) {
	texture = newTexture;
}

void Tile::render() {
	texture->render();
}

void Tile::setDestinationPoint(SDL_Point p) {
	texture->setDestinationPoint(p);
}

bool Tile::collision() {
	return collidable;
}

void Tile::setImpassible() {
	collidable = true;
}
