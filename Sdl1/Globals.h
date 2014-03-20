#ifndef GLOBALS_H
#define GLOBALS_H
#include <SDL.h>
#include <SDL_ttf.h>

namespace gameEngine {

	struct Globals {
		Globals();
		~Globals();
		SDL_Surface* screen;
		TTF_Font* font;
	};

	extern Globals sys;
}

#endif