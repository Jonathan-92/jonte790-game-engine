#include "Sprite.h"

namespace gameEngine {

	Sprite::Sprite(int x, int y, int w, int h):rect(x,y,w,h) {
	}

	Rect Sprite::getRect() const {
		return rect;
	}

	void Sprite::mouseDown(int x, int y) {
	
	}

	void Sprite::keyDown(SDLKey key) {

	}

	Sprite::~Sprite()
	{
		 
	}

}