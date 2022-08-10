#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "sfx.h"
#include "time.h"
#include "music.h"
#include "input.h"
#include "camera.h"
#include "render.h"
#include "gameMap.h"
#include "playing.h"
#include "texture.h"
#include "titleScreen.h"

int main(int argc, char* argv[]) {
	try { // Initialize SDL Systems
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
			throw "SDL_Init: ";
		if (TTF_Init() != 0)
			throw "TTF_Init: ";
		if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
			throw "IMG_Init: ";
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			throw "Mix_Init: ";

		initializeGraphics();
		loadMusic();
		loadSFX();
		loadTextures();
		loadMaps();
		initializeCamera();
	}
	catch (const char* error) {
		SDL_Log("%s%s", error, SDL_GetError());
		shutdown();
	}

	State currentState = State::None;
	State nextState = State::Title;

	while (running()) {
		if (currentState != nextState) {
			currentState = nextState;

			switch (currentState) 	{
			case State::Title:
				initializeTitleState();
				shutdownPlayState();
				break;
			case State::Playing:
				initializePlayState();
				shutdownTitleState();
				break;
			}
		}

		updateTime();
		updateSFX();
		input();

		SDL_SetRenderDrawColor(getRenderer(), 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(getRenderer());

		switch (currentState) 	{
		case State::Title:
			updateTitleState();
			renderTitleState();
			nextState = checkTitleState();
			break;
		case State::Playing:
			updatePlayState();
			renderPlayState();
			nextState = checkPlayState();
			break;
		}

		SDL_RenderPresent(getRenderer());
	}

	shutdownMusic();
	shutdownSFX();
	closeTextures();
	shutdownGraphics();

	// Shutdown SDL
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}
