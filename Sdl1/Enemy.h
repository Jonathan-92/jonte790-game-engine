#ifndef ENEMY_H
#define ENEMY_H
#include "Sprite.h"
#include <SDL.h>

class Enemy : public gameEngine::Sprite {
public:
	Enemy(int x, int y, int w, int h);
	~Enemy(void);
	void draw();
	void tick();
	static void upHealth(int h);
	void checkIfHit();
private:
	static int health;
};

#endif