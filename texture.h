#pragma once
#include <SDL.h>

class Texture {
public:
	Texture();
	Texture(SDL_Texture* newTexture);

	void render();
	void setTexture(SDL_Texture* newTexture);
	void setDestinationPoint(SDL_Point p);
	void setDestinationRect(SDL_Rect& rect);
	void setSourceRect(SDL_Rect& rect);
	int getWidth();
	int getHeight();
	void flipHorizontal();
	void flipVertical();

	void operator<<(SDL_Rect dest);

private:
	SDL_Texture* texture;
	SDL_Rect source;
	SDL_Rect destination;
	SDL_Point center;
	double angle;
	SDL_RendererFlip flip;
};

void loadTextures();
void closeTextures();

SDL_Texture* TitleTexture();
SDL_Texture* Tileset();
SDL_Texture* Sprites();