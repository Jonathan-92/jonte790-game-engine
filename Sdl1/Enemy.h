#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"
#include <SDL.h>
#include "Label.h"

class Enemy : public gameEngine::Sprite {
public:
	static void setValue(int v);
	Enemy(int x, int y, int w, int h);
	~Enemy(void);
	void tick();
	void checkIfHit();
private:
	static const int SPEED;
	static const int DAMAGE;
	static const int FINAL_CHECKPOINT;
	static int value;
	void move();
	int health;
	/* The next Checkpoint which the Enemy should move towards. */
	int nextCp;
	/* A Label displaying the current health of the Enemy. */
	gameEngine::Label* healthLabel;
};

#endif