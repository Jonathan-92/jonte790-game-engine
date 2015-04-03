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
	/* The speed with which the enemy moves. */
	static const int SPEED;

	/* The amount of lives that the enemy will take from the player
	when it reaches the end. */
	static const int DAMAGE;

	/* The last checkpoint that the enemy will move toward. */
	static const int FINAL_CHECKPOINT;

	/* The value in gold which the enemy is worth to the player when it is
	eliminated. */
	static int value;

	void move();
	int health;

	/* The next Checkpoint which the Enemy should move towards. */
	int nextCp;

	/* A Label displaying the current health of the Enemy. */
	gameEngine::Label* healthLabel;
};

#endif