#include <string>
#include <vector>

#include "Map.hpp"
#include "Layer.hpp"
#include "TileLayer.hpp"
#include "ObjectGroup.hpp"

#include "sfx.h"
#include "gameMap.h"
#include "camera.h"
#include "render.h"
#include "dragonWarrior_Tiles.h"

using namespace std;

struct MapData {
	int currentMap = 0;

	Tile* worldMap[256][256];
	Tile* tenaGaul[32][32];
	Tile* selaya[32][32];
} mapData;

void loadMap(string mapFile, Tile** mapDestination, int width) {
	tmx::Map map;

	if (map.load(mapFile)) {
		const auto& layers = map.getLayers();

		for (const auto& layer : layers) {
			if (layer->getType() == tmx::Layer::Type::Object) {
				const auto& objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
				const auto& objects = objectLayer.getObjects();
				for (const auto& object : objects) {
					//do stuff with object properties

					//***UNUSED AT MOMENT***//
				}
			}
			else if (layer->getType() == tmx::Layer::Type::Tile) {
				const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
				int x = 0, y = 0;
				for (const auto& tile : tileLayer.getTiles()) {
					switch (tile.ID - 1) { // Why are tile ID's +1?
					case 0:
						mapDestination[x + y * width] = CastleWall();
						break;
					case 1:
						mapDestination[x + y * width] = StoneWall();
						break;
					case 2:
						mapDestination[x + y * width] = ShopCounter();
						break;
					case 3:
						mapDestination[x + y * width] = Floor();
						break;
					case 4:
						mapDestination[x + y * width] = Chest();
						break;
					case 5:
						mapDestination[x + y * width] = Door();
						break;
					case 6:
						mapDestination[x + y * width] = DownStairs();
						break;
					case 7:
						mapDestination[x + y * width] = UpStairs();
						break;
					case 8:
						mapDestination[x + y * width] = DamageFloor();
						break;
					case 9:
						mapDestination[x + y * width] = EquipmentSign();
						break;
					case 10:
						mapDestination[x + y * width] = InnSign();
						break;
					case 11:
						mapDestination[x + y * width] = Castle();
						break;
					case 12:
						mapDestination[x + y * width] = Town();
						break;
					case 13:
						mapDestination[x + y * width] = Grass();
						break;
					case 14:
						mapDestination[x + y * width] = Trees();
						break;
					case 15:
						mapDestination[x + y * width] = Hill();
						break;
					case 16:
						mapDestination[x + y * width] = Mountain();
						break;
					case 17:
						mapDestination[x + y * width] = Cave();
						break;
					case 18:
						mapDestination[x + y * width] = OutsideDownStairs();
						break;
					case 19:
						mapDestination[x + y * width] = Desert();
						break;
					case 20:
						mapDestination[x + y * width] = Swamp();
						break;
					case 21:
						mapDestination[x + y * width] = TLWater();
						break;
					case 22:
						mapDestination[x + y * width] = TWater();
						break;
					case 23:
						mapDestination[x + y * width] = TRWater();
						break;
					case 24:
						mapDestination[x + y * width] = LeftCapWater();
						break;
					case 25:
						mapDestination[x + y * width] = RightCapWater();
						break;
					case 27:
						mapDestination[x + y * width] = Bridge();
						break;
					case 28:
						mapDestination[x + y * width] = LWater();
						break;
					case 29:
						mapDestination[x + y * width] = OpenWater();
						break;
					case 30:
						mapDestination[x + y * width] = RWater();
						break;
					case 31:
						mapDestination[x + y * width] = horizontalDoubleShore();
						break;
					case 32:
						mapDestination[x + y * width] = verticalDoubleShore();
						break;
					case 33:
						mapDestination[x + y * width] = FrameBackground();
						break;
					case 34:
						mapDestination[x + y * width] = PrincessStatue();
						break;
					case 35:
						mapDestination[x + y * width] = BLWater();
						break;
					case 36:
						mapDestination[x + y * width] = BWater();
						break;
					case 37:
						mapDestination[x + y * width] = BRWater();
						break;
					case 38:
						mapDestination[x + y * width] = TopCapWater();
						break;
					case 39:
						mapDestination[x + y * width] = BottomCapWater();
						break;
					default:
						mapDestination[x + y * width] = nullptr;
						break;
					}

					mapDestination[x + y * width]->ID = tile.ID - 1;

					++y;
					if (y >= width) {
						y = 0;
						++x;
					}
				}
			}
		}

		const auto& tilesets = map.getTilesets();
		for (const auto& tileset : tilesets) {
			//read out tile set properties, load textures etc...
			
			//***UNUSED BY DRAGON QUEST***//
		}
	}
	else {
		SDL_Log("Failed to load map");
	}
}

void loadMaps() {
	loadMap("assets/maps/dragon warrior.tmx", *mapData.worldMap, 256);
	loadMap("assets/maps/TenaGaul.tmx", *mapData.tenaGaul, 32);
	loadMap("assets/maps/Selaya.tmx", *mapData.selaya, 32);
}

void renderMap() {
	int x, y, xOffset, yOffset;

	SDL_Rect* camera = getCamera();

	x = camera->x / tileSize();
	y = camera->y / tileSize();

	if (x != 0)
		x -= 1;
	if (y != 0)
		y -= 1;

	int xRange = x + screenWidth() / tileSize() + 2;
	int yRange = y + screenHeight() / tileSize() + 2;

	int maxRange = mapData.currentMap == 0 ? 256 : 32;

	if (xRange > maxRange)
		xRange = maxRange;
	if (yRange > maxRange)
		yRange = maxRange;

	if (mapData.currentMap == 0) {
		for (int i = x; i < xRange; ++i) {
			for (int j = y; j < yRange; ++j) {
				mapData.worldMap[i][j]->setDestinationPoint({ i * tileSize() - camera->x, j * tileSize() - camera->y });
				mapData.worldMap[i][j]->render();
			}
		}
	}
	else if (mapData.currentMap == 1) {
		for (int i = x; i < xRange; ++i) {
			for (int j = y; j < yRange; ++j) {
				mapData.tenaGaul[i][j]->setDestinationPoint({ i * tileSize() - camera->x, j * tileSize() - camera->y });
				mapData.tenaGaul[i][j]->render();
			}
		}
	}
	else if (mapData.currentMap == 2) {
		for (int i = x; i < xRange; ++i) {
			for (int j = y; j < yRange; ++j) {
				mapData.selaya[i][j]->setDestinationPoint({ i * tileSize() - camera->x, j * tileSize() - camera->y });
				mapData.selaya[i][j]->render();
			}
		}
	}
}

int clampInt(int value, int min, int max) {
	if (value < min)
		value = min;
	else if (value > max)
		value = max;

	return value;
}

bool mapCollision(SDL_Point pos) {
	bool collision = false;

	int x, y;

	if (mapData.currentMap == 0) {
		x = clampInt(pos.x, 0, 255);
		y = clampInt(pos.y, 0, 255);

		if (x == 0 || x == 255 ||
			y == 0 || y == 255)
			collision = true;
	}
	else {
		x = clampInt(pos.x, 0, 31);
		y = clampInt(pos.y, 0, 31);

		if (x == 0 || x == 31 ||
			y == 0 || y == 31)
			collision = true;
	}

	int tile = 3;

	if (mapData.currentMap == 0)
		tile = mapData.worldMap[pos.x][pos.y]->ID;
	else if (mapData.currentMap == 1)
		tile = mapData.tenaGaul[pos.x][pos.y]->ID;
	else if (mapData.currentMap == 2)
		tile = mapData.selaya[pos.x][pos.y]->ID;

	// Passable Tiles
	if (tile != 3 &&
		tile != 6 &&
		tile != 7 &&
		tile != 8 &&
		tile != 11 &&
		tile != 12 &&
		tile != 13 &&
		tile != 14 &&
		tile != 15 &&
		tile != 17 &&
		tile != 18 &&
		tile != 19 &&
		tile != 20 &&
		tile != 27 &&
		tile != 33)
		collision = true;

	else collision = false;

	if (collision) {
		SFX_HitWall();
	}

	return collision;
}

int tileSize() {
	return screenWidth() / 16;
}

int getMapID() {
	return mapData.currentMap;
}

int getStandingTileID(SDL_Point pos) {
	return mapData.worldMap[pos.x][pos.y]->ID;
}

void switchMap(int mapID) {
	mapData.currentMap = mapID;
}