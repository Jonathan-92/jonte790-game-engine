#ifndef ENEMY_H
#define ENEMY_H
#include "Sprite.h"
#include <SDL.h>
#include "Label.h"

class Enemy : public gameEngine::Sprite {
public:
	Enemy(int x, int y, int w, int h);
	~Enemy(void);
	void draw();
	void tick();
	static void setHealth(int h);
	void checkIfHit();
	static void setValue(int v);
private:
	int health;
	int speed;
	static int value;
	gameEngine::Label* healthLabel;
	std::string update();
};

#endif