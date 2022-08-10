#include "time.h"
#include "camera.h"
#include "render.h"
#include "sprite.h"

Sprite::Sprite() {
	texture = nullptr;
}

Sprite::Sprite(Texture* spriteTexture) {
	texture = spriteTexture;
}

void Sprite::update() {
	switch (facing) {
	case Face::Up:
		clippingRect = spriteOrigin;
		clippingRect.x += spriteSize * 4;
		break;
	case Face::Down:
		clippingRect = spriteOrigin;
		break;
	case Face::Left:
		clippingRect = spriteOrigin;
		clippingRect.x += spriteSize * 6;
		break;
	case Face::Right:
		clippingRect = spriteOrigin;
		clippingRect.x += spriteSize * 2;
		break;
	}

	if (currentFrame() > 29)
		clippingRect.x += spriteSize;

	texture->setSourceRect(clippingRect);
	texture->setDestinationPoint(renderPoint);
}

void Sprite::render() {
	texture->setDestinationPoint({ renderPoint.x - getCamera()->x, renderPoint.y - getCamera()->y });
	texture->render();
}

void Sprite::face(Face direction) {
	facing = direction;
}

void Sprite::setClipRect(SDL_Rect rect) {
	spriteOrigin = rect;
}

void Sprite::setPoint(SDL_Point& point) {
	renderPoint = point;
}
