#ifndef SPRITE_H
#define SPRITE_H
#include "Rect.h"
#include <string>

namespace gameEngine {

	class Sprite {
	public:
		virtual ~Sprite();
		Rect rect;
		virtual void draw();
		virtual void tick(){}
		virtual void mouseDown(int x, int y){}
		virtual void mousePressed(int x, int y){}
		virtual void keyDown(SDL_Event& e){}
	protected:
		SDL_Texture* texture;

		// Creates a Sprite from an image path, and uses the flag transp to 
		// determine if the background should be transparent of not
		Sprite(int x, int y, int w, int h, std::string imgPath, bool transp);

		// Creates a Sprite from an SDL_Surface*
		Sprite(int x, int y, int w, int h, SDL_Surface* surface);

		// Allows for creating a Sprite that has no visibility properties
		Sprite();
	private:
		Sprite(const Sprite&);
		const Sprite& operator=(const Sprite&);
	};

}

#endif