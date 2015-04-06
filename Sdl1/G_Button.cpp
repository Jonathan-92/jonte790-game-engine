#include "G_Button.h"
#include <SDL.h>
#include <string>

using namespace std;

namespace gameEngine {

	G_Button::G_Button(int x, int y, int w, int h, std::string imgPath, 
		FuncPtr fp) : Sprite(x, y, w, h, imgPath, false), funcPtr(fp), 
		enabled(true)
	{
	}

	G_Button* G_Button::getInstance(int x, int y, int w, int h, string imgPath, FuncPtr fp) {
		return new G_Button(x, y, w, h, imgPath, fp);
	}

	G_Button::~G_Button(void)
	{
	}

	void G_Button::tick() {

	}

	void G_Button::mouseDown(int x, int y) {
		if (enabled && rect.contains(x, y)) {
			funcPtr();
		}
	}

	void G_Button::disable() {
		enabled = false;
	}

}