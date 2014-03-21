#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Sprite.h"
#include <vector>

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
		std::vector<Sprite*> getSprites() const;
	private:
		int fps;
		const char* bgPath;
		std::vector<Sprite*> sprites;
		void forAll(void (Sprite::*membrPtr)(int, int), int x, int y);
	};

	extern GameEngine ga;

}

#endif