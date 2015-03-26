#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Sprite.h"
#include <list>
#include "SDL_ttf.h"

namespace gameEngine {

	class GameEngine {
	public:
		GameEngine();
		~GameEngine();

		/* Starts the game loop */
		void run();

		/* Adds a Sprite to the game. 
		
		param "sprite" = a pointer to the Sprite that should be added. */
		void add(Sprite* sprite);

		/* Removes a Sprite from the game.
		
		param "sprite" = a pointer to the Sprite that should be removed. */
		void remove(Sprite* sprite);

		/* 
		Sets the background image of the game. This needs to be done
		before the run() function is called 
		
		param "path"= the path to the image desired as a background image.
		This needs to be a .bmp file.
		*/
		void setBackground(const char* path);

		/* 
		Sets the width and height of the game window. This needs to be done
		before the run() function is called.

		param "w" = the desired width of the window in pixels
		param "h" = the desired height  of the window in pixels 
		*/
		void setVideoMode(int w, int h);

		/* Sets the frames per second that the game should operate with.
		
		param "fps" = the frames per second. */
		void setFps(int fps);
		std::list<Sprite*> getSprites() const;
		SDL_Renderer* getRenderer() const;
		TTF_Font* getFont() const;
	private:
		SDL_Window* screen;
		SDL_Renderer* renderer;
		TTF_Font* font;
		int fps;

		/* The path for the background image */
		std::string bgPath;
		std::list<Sprite*> sprites;

		/* An iterator that will be used when removing elements while iterating */
		std::list<Sprite*>::iterator itTick;
		void forAll(void (Sprite::*membrPtr)(int, int), int x, int y);
	};

	GameEngine& ge();
	void throwException(std::string, const char* (*errorFunc)());
}

#endif