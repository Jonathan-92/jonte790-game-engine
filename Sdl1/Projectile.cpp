#include "Projectile.h"
#include "GameEngine.h"
#include "GameHandler.h"
#include <math.h>

using namespace gameEngine;

const int Projectile::WIDTH = 10;
const int Projectile::HEIGHT = 10;

Projectile::Projectile(Tower* t, int targetX, int targetY) : 
Sprite(t->rect.centeredX() - WIDTH / 2, t->rect.centeredY() - HEIGHT / 2,
WIDTH, HEIGHT, t->getProjImage(), true), damage(t->getDamage())
{
	int xDistance = targetX - t->rect.centeredX();
	int yDistance = targetY - t->rect.centeredY();
	int distance = sqrt((xDistance * xDistance) + (yDistance * yDistance));

	if (distance != 0) {
		speedX = round(t->getSpeed() * xDistance / distance);
		speedY = round(t->getSpeed() * yDistance / distance);
	}
}

Projectile::~Projectile(void)
{
	ge().remove(this);
	gh.removeProjectile(this);
}

int Projectile::getDamage() const {
	return damage;
}

void Projectile::tick() {
	rect.x += speedX;
	rect.y += speedY;

	/* Checks if the projectile traveled outside the window borders */
	bool outOfBounds = rect.x > 890 || rect.x < 0 || rect.y > 790 || rect.y < 0;

	if (outOfBounds) {
		delete this;
	}
}

