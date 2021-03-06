#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Sprite.h"
#include <list>
#include "SDL_ttf.h"

namespace gameEngine {

	/* Essentially runs the game loop and stores all Sprites in the game. It 
	also contains the SDL components like the Window and Renderer. */
	class GameEngine {
	public:
		/* Initializes all SDL components. If something fails, an exception
		is thrown. */
		GameEngine();

		~GameEngine();

		/* Starts the game loop, which loops through all Sprites which are 
		drawn on the screen and also their tick() function is called. The
		loop also checks for user events. */
		void run();

		/* Adds a Sprite to the game. 
		
		param "sprite" = a pointer to the Sprite that should be added. */
		void add(Sprite* sprite);

		/* Removes a Sprite from the game.
		
		param "sprite" = a pointer to the Sprite that should be removed. */
		void remove(Sprite* sprite);

		/* Sets the background image of the game. This needs to be done
		before the run() function is called 
		
		param "path" = the path to the image desired as a background image.
		This needs to be a .bmp file. */
		void setBackground(const char* path);

		/* Sets the width and height of the game window. This needs to be done
		before the run() function is called.

		param "w" = the desired width of the window in pixels
		param "h" = the desired height  of the window in pixels */
		void setVideoMode(int w, int h);

		/* Sets the frames per second that the game should operate with.
		
		param "fps" = the frames per second. */
		void setFps(int fps);

		SDL_Renderer* getRenderer() const;
		TTF_Font* getFont() const;
	private:
		/* This function is used when a mouseButton event has occured. The
		appropriate member function of Sprite is passed, as well as the mouse
		x and y value.

		param "membrPtr" = A pointer to a function which is a member of Sprite
		and which takes two integers as arguments and returns void.
		param "x" = The x value of the mouse position
		param "y" = The y value of the mouse position */
		void forAll(void (Sprite::*membrPtr)(int, int), int x, int y); 

		SDL_Window* window;
		SDL_Renderer* renderer;
		TTF_Font* font;

		/* The frames per second which the game should run in. */
		int fps;

		/* The path for the background image */
		std::string bgPath;

		/* A list containing all the Sprites that are used in the game. 
		The choice of datastructure fell on list because deletions will be
		performed on arbitrary positions. */
		std::list<Sprite*> sprites;

		/* An iterator that will be used when removing elements while iterating */
		std::list<Sprite*>::iterator itTick;

		bool erased;
	};

	/* A globally declared instance which makes use of the game engine's
	function easy to access. */
	GameEngine& ge();

	/* A help function for throwing an exception.
	
	param "msg" = The error message which should be printed out.
	param "errorFunc" = The error function that should be used to print
	out further details. */
	void throwException(std::string msg, const char* (*errorFunc)());
}

#endif