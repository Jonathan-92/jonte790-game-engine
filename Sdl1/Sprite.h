#ifndef SPRITE_H
#define SPRITE_H

#include "Rect.h"
#include <string>

namespace gameEngine {

	/* An abstract class that represents a visual (or non-visual) figure in the game.
	It can react on events such as mouse presses. What it does all depends on the
	implementation of the subclasses derived from this class. */
	class Sprite {
	public:
		/* This is a rectangle specifying the width, height, x, and y coordinate
		of the Sprite. */
		Rect rect;

		/* Draws the Sprite on the window. This function can be overridden
		if special behaviour is desired. */
		virtual void draw();

		/* Performs something each lap in the game loop. What it does depends
		on the implementation of the subclasses to this class. */
		virtual void tick(){}

		/* Call this function when a mouse button is clicked and pass the x and y
		coordinates of the event. */
		virtual void mouseDown(int x, int y){}

		/* Call this function when a mouse button is pressed and pass the x and y
		coordinates of the event. */
		virtual void mousePressed(int x, int y){}

		/* Call this function when a key on the keyboard is pressed and pass the 
		event */
		virtual void keyDown(SDL_Event& e){}
	protected:
		virtual ~Sprite();

		/* This is what will be copied to the renderer and displayed in the 
		window. */
		SDL_Texture* texture;

		// Creates a Sprite from an image path, and uses the flag transp to 
		// determine if the background should be transparent of not
		Sprite(int x, int y, int w, int h, std::string imgPath, bool transp);

		// Creates a Sprite from an SDL_Surface*
		Sprite(int x, int y, int w, int h, SDL_Surface* surface);

		// Allows for creating a Sprite that has no visibility properties
		Sprite();
	private:
		/* Value semantics is disabled. */
		Sprite(const Sprite&);
		const Sprite& operator=(const Sprite&);
	};

}

#endif