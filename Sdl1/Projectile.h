#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Sprite.h"
#include "Tower.h"
#include "BasicTower.h"
#include "AdvancedTower.h"

class Projectile : public gameEngine::Sprite {
public:
	Projectile(Tower* t, int targetX, int targetY);
	~Projectile(void);
	void tick();
	int damage;
private:
	static const int width;
	static const int height;
	int xDistance, yDistance;
	int speedX = 0, speedY = 0;
	int distance;
};

#endif