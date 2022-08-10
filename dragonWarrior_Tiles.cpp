#include "render.h"
#include "texture.h"
#include "dragonWarrior_Tiles.h"
#include "dragonWarrior_Sprites.h"

Tile* createTile(int x, int y) {
	int tileSize = 16;
	int displaySize = screenWidth() / 16;

	Texture* texture = new Texture(Tileset());
	Tile* tile = new Tile(texture);

	SDL_Rect source;
	source.x = x * tileSize;
	source.y = y * tileSize;
	source.w = tileSize;
	source.h = tileSize;
	texture->setSourceRect(source);

	source.w = displaySize;
	source.h = displaySize;
	texture->setDestinationRect(source);

	return tile;
}

Tile* CastleWall() {
	Tile* tile = createTile(0, 0);
	tile->setImpassible();
	return tile;
}

Tile* StoneWall() {
	Tile* tile = createTile(1, 0);
	tile->setImpassible();
	return tile;
}

Tile* ShopCounter() {
	Tile* tile = createTile(2, 0);
	tile->setImpassible();
	return tile;
}

Tile* Floor() {
	Tile* tile = createTile(3, 0);

	return tile;
}

Tile* Chest() {
	Tile* tile = createTile(4, 0);

	return tile;
}

Tile* Door() {
	Tile* tile = createTile(5, 0);
	tile->setImpassible();
	return tile;
}

Tile* DownStairs() {
	Tile* tile = createTile(6, 0);

	return tile;
}

Tile* UpStairs() {
	Tile* tile = createTile(0, 1);

	return tile;
}

Tile* DamageFloor() {
	Tile* tile = createTile(1, 1);

	return tile;
}

Tile* EquipmentSign() {
	Tile* tile = createTile(2, 1);
	tile->setImpassible();
	return tile;
}

Tile* InnSign() {
	Tile* tile = createTile(3, 1);
	tile->setImpassible();
	return tile;
}

Tile* Castle() {
	Tile* tile = createTile(4, 1);

	return tile;
}

Tile* Town() {
	Tile* tile = createTile(5, 1);

	return tile;
}

Tile* Grass() {
	Tile* tile = createTile(6, 1);

	return tile;
}

Tile* Trees() {
	Tile* tile = createTile(0, 2);

	return tile;
}

Tile* Hill() {
	Tile* tile = createTile(1, 2);

	return tile;
}

Tile* Mountain() {
	Tile* tile = createTile(2, 2);
	tile->setImpassible();
	return tile;
}

Tile* Cave() {
	Tile* tile = createTile(3, 2);

	return tile;
}

Tile* OutsideDownStairs() {
	Tile* tile = createTile(4, 2);

	return tile;
}

Tile* Desert() {
	Tile* tile = createTile(5, 2);

	return tile;
}

Tile* Swamp() {
	Tile* tile = createTile(6, 2);

	return tile;
}

Tile* Bridge() {
	Tile* tile = createTile(6, 3);

	return tile;
}

Tile* PrincessStatue() {
	Tile* tile = createTile(6, 4);
	tile->setImpassible();
	return tile;
}

Tile* OpenWater() {
	Tile* tile = createTile(1, 4);
	tile->setImpassible();
	return tile;
}

Tile* TLWater() {
	Tile* tile = createTile(0, 3);
	tile->setImpassible();
	return tile;
}

Tile* TWater() {
	Tile* tile = createTile(1, 3);
	tile->setImpassible();
	return tile;
}

Tile* TRWater() {
	Tile* tile = createTile(2, 3);
	tile->setImpassible();
	return tile;
}

Tile* BLWater() {
	Tile* tile = createTile(0, 5);
	tile->setImpassible();
	return tile;
}

Tile* BWater() {
	Tile* tile = createTile(1, 5);
	tile->setImpassible();
	return tile;
}

Tile* BRWater() {
	Tile* tile = createTile(2, 5);
	tile->setImpassible();
	return tile;
}

Tile* LWater() {
	Tile* tile = createTile(0, 4);
	tile->setImpassible();
	return tile;
}

Tile* RWater() {
	Tile* tile = createTile(2, 4);
	tile->setImpassible();
	return tile;
}

Tile* horizontalDoubleShore() {
	Tile* tile = createTile(3, 4);
	tile->setImpassible();
	return tile;
}

Tile* verticalDoubleShore() {
	Tile* tile = createTile(4, 4);
	tile->setImpassible();
	return tile;
}

Tile* LeftCapWater() {
	Tile* tile = createTile(3, 3);
	tile->setImpassible();
	return tile;
}

Tile* RightCapWater() {
	Tile* tile = createTile(4, 3);
	tile->setImpassible();
	return tile;
}

Tile* TopCapWater() {
	Tile* tile = createTile(3, 5);
	tile->setImpassible();
	return tile;
}

Tile* BottomCapWater() {
	Tile* tile = createTile(4, 5);
	tile->setImpassible();
	return tile;
}

Tile* TopFrame() {
	Tile* tile = createTile(5, 3);
	tile->setImpassible();
	return tile;
}

Tile* BottomFrame() {
	Tile* tile = createTile(5, 5);
	tile->setImpassible();
	return tile;
}

Tile* FrameBackground() {
	Tile* tile = createTile(5, 4);

	return tile;
}

Tile* Darkness() {
	Tile* tile = createTile(6, 5);
	tile->setImpassible();
	return tile;
}
