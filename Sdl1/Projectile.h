#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Sprite.h"
#include "Tower.h"

class Projectile : public gameEngine::Sprite {
public:
	Projectile(Tower* t, int targetX, int targetY);
	~Projectile(void);
	int getDamage() const;
	void tick();
private:
	static const int WIDTH;
	static const int HEIGHT;

	/* The amount of pixels that this instance should move in x and y
	respectively. */
	int speedX, speedY;

	/* The amount of hitpoints this instance will take from an enemy when it
	is hit. */
	int damage;
};

#endif