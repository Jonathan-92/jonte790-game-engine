#include "Projectile.h"
#include "Tower.h"
#include "GameEngine.h"
#include "Spawner.h"
#include "GameHandler.h"

using namespace gameEngine;

Projectile::Projectile(int towerX, int towerY, int targetX, int targetY, 
	int w, int h, int dmg, int spd, std::string img) : Sprite(towerX, towerY, w, h, img), 
	damage(dmg), speed(spd), towerX(towerX), towerY(towerY), xTarget(targetX), yTarget(targetY)
{
	xDistance = xTarget - towerX;
	yDistance = yTarget - towerY;
	distance = sqrt((xDistance * xDistance) + (yDistance * yDistance));

	if (distance != 0) {
		speedX = speed * xDistance / distance;
		speedY = speed * yDistance / distance;
	}
}


Projectile::~Projectile(void)
{
	gh.removeProjectile(this);
	ga.remove(this);
}

void Projectile::tick() {
	rect.x += speedX;
	rect.y += speedY;
	bool outOfBounds = rect.x > 890 || rect.x < 0 || rect.y > 790 || rect.y < 0;

	if (outOfBounds) {
		delete this;
	}
}

int Projectile::getDamage() {
	return damage;
}

