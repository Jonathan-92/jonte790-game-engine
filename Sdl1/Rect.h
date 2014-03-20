#ifndef RECT_H
#define RECT_H
#include <SDL.h>

namespace gameEngine {

	struct Rect : public SDL_Rect {
	public:
		Rect();
		Rect(int xx, int yy, int ww, int hh);
		bool contains(int xx, int yy) const;
		Rect centeredRect(int width, int height) const;
		bool overlaps(const Rect& other) const;
	};
}

#endif
