#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Sprite.h"
#include "Tower.h"

class Projectile : public gameEngine::Sprite {
public:
	Projectile(int x, int y, int w, int h);
	~Projectile(void);
	void draw();
	void tick();
	void setTarget(int x, int y);
private:
	int towerX, towerY;
	int yTarget;
	int xTarget;
	int yRatio;
	int xRatio;
};

#endif