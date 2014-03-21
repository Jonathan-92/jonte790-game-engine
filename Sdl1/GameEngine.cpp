#include "GameEngine.h"
#include "Globals.h"
#include <SDL.h>
#include <string>
#include <iostream>

namespace gameEngine {

	GameEngine ga;

	GameEngine::GameEngine() : fps(60) {
		sys.screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
	}

	void GameEngine::setVideoMode(int w, int h) {
		sys.screen = SDL_SetVideoMode(w, h, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
	}

	void GameEngine::setFps(int i) {
		fps = i;
	}

	std::vector<Sprite*> GameEngine::getSprites() const {
		return sprites;
	}

	void GameEngine::run() {

		SDL_Surface* background = SDL_LoadBMP(bgPath);	// undantagshantering?
		bool quit = false;

		const int tickInterval = 1000 / fps;
		Uint32 nextTick;
		int delay;

		do {
			nextTick = SDL_GetTicks() + tickInterval;
			SDL_BlitSurface(background, NULL, sys.screen, NULL);

			for (std::vector<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); it++) {
				(*it)->draw();
			}

			SDL_Flip(sys.screen);
			SDL_Event event;

			while (SDL_PollEvent(&event)) {

				switch (event.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
					forAll(&Sprite::mouseDown, event.button.x, event.button.y);
					break;
				}

			}

			for (std::vector<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); it++) {
				(*it)->tick();
			}

			delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);

		} while (!quit);
	}
	
	void GameEngine::forAll(void (Sprite::*membrPtr)(int, int), int x, int y) {
		for (std::vector<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); it++) {
			((*it)->*membrPtr)(x, y);
		}
	}

	void GameEngine::add(Sprite* sprite) {
		sprites.push_back(sprite);
	}

	void GameEngine::remove(Sprite* sprite) {
		/*std::vector<Sprite*>::iterator position = std::find(sprites.begin(), sprites.end(), sprite);
		if (position != sprites.end())
			sprites.erase(position);*/
	}

	void GameEngine::setBackground(const char* path) {
		bgPath = path;
	}

	GameEngine::~GameEngine(void)
	{
		for (std::vector<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); it++) {
			delete (*it);
		}
	}
}