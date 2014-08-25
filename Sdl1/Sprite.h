#ifndef SPRITE_H
#define SPRITE_H
#include "Rect.h"

namespace gameEngine {

	class Sprite {
	public:
		virtual ~Sprite();
		Rect rect;
		Rect getRect() const;
		virtual void draw() = 0;
		virtual void tick() = 0;
		virtual void mouseDown(int x, int y);
		virtual void keyDown(SDLKey key);
	protected:
		SDL_Surface* image;
		Sprite(int x, int y, int w, int h);
	private:
		Sprite(const Sprite&);
		const Sprite& operator=(const Sprite&);
	};

}

#endif