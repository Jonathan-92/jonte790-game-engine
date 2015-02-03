#ifndef ENEMY_H
#define ENEMY_H
#include "Sprite.h"
#include <SDL.h>
#include "Label.h"

class Enemy : public gameEngine::Sprite {
public:
	Enemy(int x, int y, int w, int h);
	~Enemy(void);
	void tick();
	static void setHealth(int h);
	void checkIfHit();
	static void setValue(int v);
private:
	static int const SPEED = 2;
	static int const DAMAGE = 1;
	static const int FINISHED = 5;
	static int value;
	int health;
	int nextCp;
	gameEngine::Label* healthLabel;
	void move();
};

#endif