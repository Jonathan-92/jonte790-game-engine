#ifndef TOWER_H
#define TOWER_H
#include "Sprite.h"

class Tower : public gameEngine::Sprite {
public:
	Tower(int x, int y, int w, int h);
	~Tower(void);
	void draw();
	void tick();
	void mouseDown(int x, int y);
};

#endif