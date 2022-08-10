#include "gameMap.h"
#include "time.h"
#include "input.h"
#include "camera.h"
#include "player.h"
#include "render.h"
#include "dragonWarrior_Sprites.h"

enum struct Moving {
	None, Up, Down, Left, Right
};

struct Player {
	Sprite* currentSprite;

	Sprite* unarmed;
	Sprite* swordEquiped;
	Sprite* shieldEquipped;
	Sprite* swordAndShieldEquiped;
	Sprite* princessEquiped;

	int speed = 16;
	int distance = 0;
	Moving moving;
	SDL_Point location;
} player;

void initializePlayer() {
	player.unarmed = Hero_Unequiped();
	player.swordEquiped = Hero_Sword();
	player.shieldEquipped = Hero_Shield();
	player.swordAndShieldEquiped = Hero_SwordAndShield();
	player.princessEquiped = Hero_Princess();

	player.currentSprite = player.unarmed;
	player.location.x = tileSize() * 211;
	player.location.y = tileSize() * 61;

	player.moving = Moving::None;
}


void move() {
	bool centered;

	if (player.distance != 0) {
		switch (player.moving) {
		case Moving::Up:
			player.location.y -= tileSize() / player.speed;
			break;
		case Moving::Down:
			player.location.y += tileSize() / player.speed;
			break;
		case Moving::Left:
			player.location.x -= tileSize() / player.speed;
			break;
		case Moving::Right:
			player.location.x += tileSize() / player.speed;
			break;
		}

		if (player.location.y < 0)
			player.location.y = 0;
		else if (player.location.x < 0)
			player.location.x = 0;
		else if (player.location.y > tileSize() * 255)
			player.location.y = tileSize() * 255;
		else if (player.location.x > tileSize() * 255)
			player.location.x = tileSize() * 255;

		player.distance -= tileSize() / player.speed;
	}
	else {
		if (keyPressed(SDLK_w) || keyPressed(SDLK_UP)) {
			player.currentSprite->face(Face::Up);
			player.moving = Moving::Up;
		}
		else if (keyPressed(SDLK_s) || keyPressed(SDLK_DOWN)) {
			player.currentSprite->face(Face::Down);
			player.moving = Moving::Down;
		}
		else if (keyPressed(SDLK_a) || keyPressed(SDLK_LEFT)) {
			player.currentSprite->face(Face::Left);
			player.moving = Moving::Left;
		}
		else if (keyPressed(SDLK_d) || keyPressed(SDLK_RIGHT)) {
			player.currentSprite->face(Face::Right);
			player.moving = Moving::Right;
		}
		else {
			player.moving = Moving::None;
			player.distance = 0;
		}

		SDL_Point pos;
		pos.x = player.location.x / tileSize();
		pos.y = player.location.y / tileSize();

		if (player.moving == Moving::Up && !mapCollision({ pos.x, pos.y - 1 }))
			player.distance = tileSize();
		else if (player.moving == Moving::Down && !mapCollision({ pos.x, pos.y + 1 }))
			player.distance = tileSize();
		else if (player.moving == Moving::Left && !mapCollision({ pos.x - 1, pos.y }))
			player.distance = tileSize();
		else if (player.moving == Moving::Right && !mapCollision({ pos.x + 1, pos.y }))
			player.distance = tileSize();

		else {
			player.moving = Moving::None;
			player.distance = 0;
		}
	}
}

void updatePlayer() {
	move();
	player.currentSprite->setPoint(player.location);
	player.currentSprite->update();
}

void renderPlayer() {
	player.currentSprite->render();
}

int getXPos() {
	return player.location.x;
}

int getYPos() {
	return player.location.y;
}

void setPlayerPos(SDL_Point pos) {
	player.location.x = tileSize() * pos.x;
	player.location.y = tileSize() * pos.y;
}
