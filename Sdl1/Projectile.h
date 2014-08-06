#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Sprite.h"
#include "Tower.h"

class Projectile : public gameEngine::Sprite {
public:
	Projectile(int towerX, int towerY, int targetX, int targetY, int w, int h, int damage, int speed, const char* image);
	~Projectile(void);
	void draw();
	void tick();
	int getDamage();
private:
	int damage;
	int speed;
	int towerX, towerY;
	int yTarget;
	int xTarget;
	int xDistance, yDistance;
	int speedX, speedY;
	int distance;
};

#endif