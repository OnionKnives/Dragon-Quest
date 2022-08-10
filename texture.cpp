#include <vector>
#include <SDL_image.h>

#include "render.h"
#include "texture.h"

using namespace std;

struct TextureLibrary {
	SDL_Texture* title = nullptr;
	SDL_Texture* tiles = nullptr;
	SDL_Texture* sprites = nullptr;
} library;

SDL_Texture* loadTextureFromFile(const char* filepath) {
	SDL_Surface* surface = IMG_Load(filepath);
	SDL_Texture* finalTexture = nullptr;

	try {
		if (surface == nullptr)
			throw IMG_GetError();

		finalTexture = SDL_CreateTextureFromSurface(getRenderer(), surface);
		if (finalTexture == nullptr)
			throw IMG_GetError();

		SDL_FreeSurface(surface);
	}
	catch (const char* error) {
		SDL_Log("%s, %s", error, SDL_GetError());
	}

	return finalTexture;
}

void loadTextures() {
	const char* filePath = "assets\\art\\dragonWarriorTitle.png";
	library.title = loadTextureFromFile("assets\\art\\dragonWarriorTitle.png");
	library.tiles = loadTextureFromFile("assets\\art\\dragonWarriorTileset.png");
	library.sprites = loadTextureFromFile("assets\\art\\dragonWarriorSprites.png");
}

void closeTextures() {
	SDL_DestroyTexture(library.title);
	SDL_DestroyTexture(library.tiles);
	SDL_DestroyTexture(library.sprites);
}

SDL_Texture* TitleTexture() {
	return library.title;
}

SDL_Texture* Tileset() {
	return library.tiles;
}

SDL_Texture* Sprites() {
	return library.sprites;
}


Texture::Texture() {
	texture = nullptr;

	source.x = 0;
	source.y = 0;
	source.w = 0;
	source.h = 0;

	destination = source;

	center.x = source.w / 2;
	center.y = source.h / 2;

	angle = 0.0;
	flip = SDL_FLIP_NONE;
}

Texture::Texture(SDL_Texture* newTexture) {
	texture = newTexture;

	source.x = 0;
	source.y = 0;
	SDL_QueryTexture(texture, nullptr, nullptr, &source.w, &source.h);

	destination = source;

	center.x = source.w / 2;
	center.y = source.h / 2;

	angle = 0.0;
	flip = SDL_FLIP_NONE;
}

void Texture::render() {
	if (texture != nullptr)
		SDL_RenderCopyEx(
			getRenderer(),
			texture, &source, &destination,
			angle, &center, flip);
}

void Texture::setTexture(SDL_Texture* newTexture) {
	texture = newTexture;
}

void Texture::setDestinationPoint(SDL_Point p) {
	destination.x = p.x;
	destination.y = p.y;
}

void Texture::setDestinationRect(SDL_Rect& rect) {
	destination = rect;
}

void Texture::setSourceRect(SDL_Rect& rect) {
	source = rect;
}

int Texture::getWidth() {
	return source.w;
}

int Texture::getHeight() {
	return source.h;
}

void Texture::flipHorizontal() {
	if (flip == SDL_FLIP_HORIZONTAL)
		flip = SDL_FLIP_NONE;
	else
		flip = SDL_FLIP_HORIZONTAL;
}

void Texture::flipVertical() {
	if (flip == SDL_FLIP_VERTICAL)
		flip = SDL_FLIP_NONE;
	else
		flip = SDL_FLIP_VERTICAL;
}

void Texture::operator<<(SDL_Rect dest) {
	destination = dest;
}
