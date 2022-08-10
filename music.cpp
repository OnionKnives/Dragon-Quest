#include <SDL_mixer.h>

#include "music.h"

struct Music {
	Mix_Music* titleScreen = nullptr;
	Mix_Music* overworld = nullptr;
	Mix_Music* tantegalCastle = nullptr;
	Mix_Music* village = nullptr;
} musicLibrary;

void loadMusic() {
	musicLibrary.titleScreen = Mix_LoadMUS("assets\\music\\01 Dragon Quest 1 - Intro ~ Overture.mp3");
	musicLibrary.overworld = Mix_LoadMUS("assets\\music\\05 Dragon Quest 1 - Kingdom of Alefgard.mp3");
	musicLibrary.tantegalCastle = Mix_LoadMUS("assets\\music\\03 Dragon Quest 1 - Tantegel Castle (Lower).mp3");
	musicLibrary.village = Mix_LoadMUS("assets\\music\\04 Dragon Quest 1 - Peaceful Village.mp3");

	Mix_VolumeMusic(16);
}

void shutdownMusic() {
	Mix_FreeMusic(musicLibrary.titleScreen);
	Mix_FreeMusic(musicLibrary.overworld);
	Mix_FreeMusic(musicLibrary.tantegalCastle);
	Mix_FreeMusic(musicLibrary.village);
}

void playIntroMusic() {
	Mix_PlayMusic(musicLibrary.titleScreen, -1);
}

void playOverworldMusic() {
	Mix_PlayMusic(musicLibrary.overworld, -1);
}

void playCastleMusic() {
	Mix_PlayMusic(musicLibrary.tantegalCastle, -1);
}

void playVillageMusic() {
	Mix_PlayMusic(musicLibrary.village, -1);
}