#include "render.h"
#include "texture.h"
#include "dragonWarrior_Sprites.h"

Sprite* createSprite(int x, int y) {
	int tileSize = 16;
	int displaySize = screenWidth() / 16 + 1;

	Texture* texture = new Texture(Sprites());
	Sprite* sprite = new Sprite(texture);

	SDL_Rect source;
	source.x = x * tileSize;
	source.y = y * tileSize;
	source.w = tileSize;
	source.h = tileSize;
	texture->setSourceRect(source);

	sprite->setClipRect(source);

	source.w = displaySize;
	source.h = displaySize;
	texture->setDestinationRect(source);

	return sprite;
}

Sprite* Hero_Unequiped() {
	return createSprite(0, 0);
}

Sprite* Hero_Sword() {
	return createSprite(8, 0);
}

Sprite* Hero_Shield() {
	return createSprite(0, 1);
}

Sprite* Hero_SwordAndShield() {
	return createSprite(8, 1);
}

Sprite* Hero_Princess() {
	return createSprite(0, 2);
}

Sprite* King() {
	return createSprite(8, 2);
}

Sprite* Princess() {
	return createSprite(10, 2);
}

Sprite* DragonLord() {
	return createSprite(12, 2);
}

Sprite* Trumpets() {
	return createSprite(14, 2);
}

Sprite* Pikeman() {
	return createSprite(0, 3);
}

Sprite* Knight() {
	return createSprite(8, 3);
}

Sprite* Wizard() {
	return createSprite(0, 4);
}

Sprite* ShopKeeper() {
	return createSprite(8, 4);
}

Sprite* Male() {
	return createSprite(0, 5);
}

Sprite* Female() {
	return createSprite(8, 5);
}
