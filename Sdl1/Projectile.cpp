#include "Projectile.h"
#include "GameEngine.h"
#include "GameHandler.h"
#include <math.h>

using namespace gameEngine;

Projectile::Projectile(Tower* t, int targetX, int targetY) : 
Sprite(t->rect.centeredX() - width / 2, t->rect.centeredY() - height / 2,
width, height, t->projImage, true), damage(t->damage)
{
	xDistance = targetX - t->rect.centeredX();
	yDistance = targetY - t->rect.centeredY();
	distance = sqrt((xDistance * xDistance) + (yDistance * yDistance));

	if (distance != 0) {
		speedX = round(t->speed * xDistance / distance);
		speedY = round(t->speed * yDistance / distance);
	}
}

Projectile::~Projectile(void)
{
	ge().remove(this);
	gh.removeProjectile(this);
}

const int Projectile::width = 10;
const int Projectile::height = 10;

void Projectile::tick() {
	rect.x += speedX;
	rect.y += speedY;
	bool outOfBounds = rect.x > 890 || rect.x < 0 || rect.y > 790 || rect.y < 0;

	if (outOfBounds) {
		delete this;
	}
}

