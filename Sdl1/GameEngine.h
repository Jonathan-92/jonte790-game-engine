#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Sprite.h"
#include <list>

namespace gameEngine {

	class GameEngine {
	public:
		GameEngine();
		~GameEngine();
		void run();
		void add(Sprite* sprite);
		void remove(Sprite* sprite);
		void setBackground(const char* path);
		void setVideoMode(int w, int h);
		void setFps(int i);
		std::list<Sprite*> getSprites() const;
	private:
		int fps;
		const char* bgPath;
		std::list<Sprite*> sprites;
		void forAll(void (Sprite::*membrPtr)(int, int), int x, int y);
		std::list<Sprite*>::iterator itTick;
	};

	extern GameEngine ga;

}

#endif