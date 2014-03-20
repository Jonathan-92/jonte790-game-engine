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
	protected:
		SDL_Surface* image;
		Sprite(int x, int y, int w, int h);
	private:
		Sprite(const Sprite&);
		const Sprite& operator=(const Sprite&);
	};

}

#endif