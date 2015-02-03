#include "Sprite.h"
#include "GameEngine.h"

namespace gameEngine {

	Sprite::Sprite(int x, int y, int w, int h, std::string imgPath) :
		rect(x, y, w, h)
	{
		setTexture(SDL_LoadBMP(imgPath.c_str()));
	}

	Sprite::Sprite(int x, int y, int w, int h, SDL_Surface* surface) :
		rect(x, y, w, h)
	{
		setTexture(surface);
	}

	void Sprite::setTexture(SDL_Surface* surface) {
		Uint32 transp = *(Uint32*)surface->pixels;
		SDL_SetColorKey(surface, SDL_RLEACCEL, transp);
		texture = SDL_CreateTextureFromSurface(ga.getRenderer(), surface);
		SDL_FreeSurface(surface);
	}

	Sprite::Sprite() {
		// "invisible" sprite
	}

	void Sprite::draw() {
		SDL_RenderCopy(ga.getRenderer(), texture, nullptr, &rect);
	}

	Sprite::~Sprite()
	{
		 
	}

}