#include <SDL.h>
#include <SDL_mixer.h>

#include "sfx.h"

struct SFX {
	Mix_Chunk* menu = nullptr;
	Mix_Chunk* walls = nullptr;
	int wallsTimer = 0;
} sfxLibrary;

void loadSFX() {
	sfxLibrary.walls = Mix_LoadWAV("assets/sfx/42 Dragon Quest 1 - Bumping into Walls.wav");
	Mix_VolumeChunk(sfxLibrary.walls, 16);

	sfxLibrary.menu = Mix_LoadWAV("assets/sfx/32 Dragon Quest 1 - Menu Button.wav");
	Mix_VolumeChunk(sfxLibrary.menu, 16);
}

void updateSFX() {
	++sfxLibrary.wallsTimer;
	if (sfxLibrary.wallsTimer >= 18) {
		sfxLibrary.wallsTimer = 0;
	}
}

void shutdownSFX() {
	Mix_FreeChunk(sfxLibrary.walls);
	Mix_FreeChunk(sfxLibrary.menu);
}

void SFX_HitWall() {
	if (sfxLibrary.wallsTimer == 0)
		Mix_PlayChannel(-1, sfxLibrary.walls, 0);
}

void SFX_Menu() {
	Mix_PlayChannel(-1, sfxLibrary.menu, 0);
}
