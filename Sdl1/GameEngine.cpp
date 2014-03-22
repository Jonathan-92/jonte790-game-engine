#include "GameEngine.h"
#include "Globals.h"
#include <SDL.h>
#include <string>
#include <iostream>
#include "Enemy.h"

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

	std::list<Sprite*> GameEngine::getSprites() const {
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

			for (std::list<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); it++) {
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

			for (itTick = sprites.begin(); itTick != sprites.end(); ++itTick) {
				(*itTick)->tick();
			}

			delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);

		} while (!quit);
	}
	
	void GameEngine::forAll(void (Sprite::*membrPtr)(int, int), int x, int y) {
		for (std::list<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); it++) {
			((*it)->*membrPtr)(x, y);
		}
	}

	void GameEngine::add(Sprite* sprite) {
		sprites.push_back(sprite);
	}

	void GameEngine::remove(Sprite* sprite) {
		if (dynamic_cast<Enemy*>(sprite) != NULL) {
			itTick++;
		}

		sprites.remove(sprite);
	}

	void GameEngine::setBackground(const char* path) {
		bgPath = path;
	}

	GameEngine::~GameEngine(void)
	{
		for (std::list<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); it++) {
			delete (*it);
		}
	}
}