#include <SDL.h>

#include "render.h"
#include "texture.h"

struct WindowData {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	int width = 640;
	int height = 480;
} graphics;

void initializeGraphics() {
	try {
		graphics.window = SDL_CreateWindow("Dragon Warrior",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			graphics.width, graphics.height,
			0);

		if (graphics.window == nullptr)
			throw "Window failed to initialize";

		graphics.renderer = SDL_CreateRenderer(graphics.window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (graphics.renderer == nullptr)
			throw "Renderer failed to initialize";

		SDL_SetRenderDrawBlendMode(graphics.renderer, SDL_BLENDMODE_BLEND);
	}
	catch (const char* error) {
		SDL_Log("%s, %s", error, SDL_GetError());
	}
}

void shutdownGraphics() {
	SDL_DestroyRenderer(graphics.renderer);
	SDL_DestroyWindow(graphics.window);
}

int screenWidth() {
	return graphics.width;
}

int screenHeight() {
	return graphics.height;
}

SDL_Renderer* getRenderer() {
	return graphics.renderer;
}
