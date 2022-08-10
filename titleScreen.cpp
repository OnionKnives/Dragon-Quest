#include <SDL.h>

#include "sfx.h"
#include "text.h"
#include "time.h"
#include "input.h"
#include "music.h"
#include "state.h"
#include "render.h"
#include "playing.h"
#include "titleScreen.h"
#include "dragonWarrior_Tiles.h"

struct Title {
	Texture* title = nullptr;
	Tile* topFrame = nullptr;
	Tile* bottomFrame = nullptr;
	Tile* middle = nullptr;

	SDL_Rect selectLeft;
	SDL_Rect selectRight;

	Text newGame;
	Text loadGame;
	Text quit;

	bool cursorMoved = false;
	int elapsedTime = 0;

	State nextState = State::Title;
} titleState;

void initializeTitleState() {
	// Title
	titleState.title = new Texture(TitleTexture());

	SDL_Rect destRect;
	destRect.w = titleState.title->getWidth() * 2.5;
	destRect.h = titleState.title->getHeight() * 2.5;
	destRect.x = screenWidth() / 2 - destRect.w / 2;
	destRect.y = 160 - destRect.h / 2;

	*titleState.title << destRect;

	titleState.topFrame = TopFrame();
	titleState.bottomFrame = BottomFrame();
	titleState.middle = FrameBackground();

	titleState.newGame << "New Game";
	titleState.loadGame << "Load Game";
	titleState.quit << "Quit";

	SDL_Point point;
	point.x = screenWidth() / 2;
	point.y = (screenWidth() / 16) * 8.5;

	titleState.newGame.setRenderPoint(point);

	point.y += 40;
	titleState.loadGame.setRenderPoint(point);

	point.y += 40;
	titleState.quit.setRenderPoint(point);

	titleState.selectLeft.w = 10;
	titleState.selectLeft.h = 10;
	titleState.selectLeft.y = 340 - titleState.newGame.getHeight() / 2 + 5;
	titleState.selectLeft.x = (screenWidth() / 2) - (titleState.newGame.getWidth() / 2) - 30;

	titleState.selectRight = titleState.selectLeft;
	titleState.selectRight.x = (screenWidth() / 2) + (titleState.newGame.getWidth() / 2) + 20;
	playIntroMusic();
}

void shutdownTitleState() {
	delete titleState.title;
}

void updateTitleState() {
	int newGameLoc = 340 - titleState.newGame.getHeight() / 2 + 5;
	int loadGameLoc = 380 - titleState.newGame.getHeight() / 2 + 5;
	int quitLoc = 420 - titleState.newGame.getHeight() / 2 + 5;
	
	if (!titleState.cursorMoved) {
		if (keyPressed(SDLK_DOWN)) {
			if (titleState.selectLeft.y == newGameLoc) {
				titleState.selectLeft.y = loadGameLoc;
				titleState.selectRight.y = loadGameLoc;
				titleState.selectLeft.x = screenWidth() / 2 - titleState.loadGame.getWidth() / 2 - 30;
				titleState.selectRight.x = (screenWidth() / 2) + (titleState.loadGame.getWidth() / 2) + 15;
				titleState.cursorMoved = true;
			}
			else if (titleState.selectLeft.y == loadGameLoc) {
				titleState.selectLeft.y = quitLoc;
				titleState.selectRight.y = quitLoc;
				titleState.selectLeft.x = screenWidth() / 2 - titleState.quit.getWidth() / 2 - 30;
				titleState.selectRight.x = (screenWidth() / 2) + (titleState.quit.getWidth() / 2) + 15;
				titleState.cursorMoved = true;
			}
			else if (titleState.selectLeft.y == quitLoc) {
				titleState.selectLeft.y = newGameLoc;
				titleState.selectRight.y = newGameLoc;
				titleState.selectLeft.x = screenWidth() / 2 - titleState.newGame.getWidth() / 2 - 30;
				titleState.selectRight.x = (screenWidth() / 2) + (titleState.newGame.getWidth() / 2) + 15;
				titleState.cursorMoved = true;
			}
		}

		else if (keyPressed(SDLK_UP)) {
			if (titleState.selectLeft.y == newGameLoc) {
				titleState.selectLeft.y = quitLoc;
				titleState.selectRight.y = quitLoc;
				titleState.selectLeft.x = screenWidth() / 2 - titleState.quit.getWidth() / 2 - 30;
				titleState.selectRight.x = (screenWidth() / 2) + (titleState.quit.getWidth() / 2) + 15;
				titleState.cursorMoved = true;
			}
			else if (titleState.selectLeft.y == loadGameLoc) {
				titleState.selectLeft.y = newGameLoc;
				titleState.selectRight.y = newGameLoc;
				titleState.selectLeft.x = screenWidth() / 2 - titleState.newGame.getWidth() / 2 - 30;
				titleState.selectRight.x = (screenWidth() / 2) + (titleState.newGame.getWidth() / 2) + 15;
				titleState.cursorMoved = true;
			}
			else if (titleState.selectLeft.y == quitLoc) {
				titleState.selectLeft.y = loadGameLoc;
				titleState.selectRight.y = loadGameLoc;
				titleState.selectLeft.x = screenWidth() / 2 - titleState.loadGame.getWidth() / 2 - 30;
				titleState.selectRight.x = (screenWidth() / 2) + (titleState.loadGame.getWidth() / 2) + 15;
				titleState.cursorMoved = true;
			}
		}

		if (titleState.cursorMoved)
			SFX_Menu();
	}
	else if (titleState.cursorMoved) {
		titleState.elapsedTime++;
		if (titleState.elapsedTime >= 8) {
			titleState.elapsedTime = 0;
			titleState.cursorMoved = false;
		}
	}

	if (keyPressed(SDLK_RETURN)) {
		if (titleState.selectLeft.y == newGameLoc) {
			titleState.nextState = State::Playing;
		}
		else if (titleState.selectLeft.y == loadGameLoc) {
			SDL_Log("Load Game");
		}
		else if (titleState.selectLeft.y == quitLoc) {
			shutdown();
		}
	}
}

void renderTitleState() {
	int tileSize = screenWidth() / 16;
	int columns = 16;

	for (int i = 0; i < columns; ++i) {
		titleState.topFrame->setDestinationPoint({ tileSize * i, tileSize });
		titleState.topFrame->render();
	}

	for (int i = 0; i < columns; ++i) {
		for (int row = 0; row < 4; ++row) {
			titleState.middle->setDestinationPoint({ tileSize * i, tileSize * (2 + row) });
			titleState.middle->render();
		}
	}

	for (int i = 0; i < columns; ++i) {
		titleState.bottomFrame->setDestinationPoint({ tileSize * i, tileSize * 6 });
		titleState.bottomFrame->render();
	}

	titleState.title->render();

	SDL_SetRenderDrawColor(getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(getRenderer(), &titleState.selectLeft);
	SDL_RenderFillRect(getRenderer(), &titleState.selectRight);

	titleState.newGame.render();
	titleState.loadGame.render();
	titleState.quit.render();
}

State checkTitleState() {
	return titleState.nextState;
}
