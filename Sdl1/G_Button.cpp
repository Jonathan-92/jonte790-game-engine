#include "G_Button.h"

#include <SDL.h>
#include <string>

namespace gameEngine {

	G_Button::G_Button(int x, int y, int w, int h, std::string imgPath, 
		FuncPtr fp) : Sprite(x, y, w, h, imgPath, false), funcPtr(fp) 
	{
	}

	G_Button::~G_Button(void)
	{
	}

	void G_Button::tick() {

	}

	void G_Button::mouseDown(int x, int y) {
		if (rect.contains(x, y)) {
			funcPtr();
		}
	}

}