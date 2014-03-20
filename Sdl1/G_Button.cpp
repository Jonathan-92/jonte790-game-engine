#include "G_Button.h"
#include "Globals.h"
#include <SDL.h>

using namespace gameEngine;

G_Button::G_Button(int x, int y, int w, int h, const char* imgPath, FuncPtr fp) : Sprite(x, y, w, h), funcPtr(fp) {
	image = SDL_LoadBMP(imgPath);
}

G_Button::~G_Button(void)
{
}

void G_Button::draw() {
	SDL_BlitSurface(image, NULL, sys.screen, &rect);
}

void G_Button::tick() {

}

void G_Button::mouseDown(int x, int y) {
	if (getRect().contains(x, y)) {
		funcPtr();
	}
}