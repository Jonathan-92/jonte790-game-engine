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
	static const int width;
	static const int height;
	int xDistance, yDistance;
	int speedX, speedY;
	int distance;
	int damage;
};

#endif