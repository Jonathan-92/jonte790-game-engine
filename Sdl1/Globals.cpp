#include "Globals.h"
#include <SDL.h>
#include <SDL_ttf.h>

namespace gameEngine {

	Globals::Globals()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/arialbd.ttf",20);
	}

	Globals::~Globals()
	{
		SDL_Quit();
		TTF_CloseFont(font);
		TTF_Quit();
	}

	Globals sys;

}