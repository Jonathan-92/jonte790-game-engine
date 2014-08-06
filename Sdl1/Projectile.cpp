#include "Projectile.h"
#include "Globals.h"
#include "Tower.h"
#include "GameEngine.h"
#include "Spawner.h"

using namespace gameEngine;

Projectile::Projectile(int towerX, int towerY, int targetX, int targetY, 
	int w, int h, int dmg, int spd, const char* img) : Sprite(towerX, towerY, w, h), 
	damage(dmg), speed(spd), towerX(towerX), towerY(towerY), xTarget(targetX), yTarget(targetY)
{
	image = SDL_DisplayFormat(SDL_LoadBMP(img));
	Uint32 transp = *(Uint32*)image->pixels;
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
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
	Spawner::removeProjectile(this);
	ga.remove(this);
}


void Projectile::draw() {
	SDL_BlitSurface(image, NULL, sys.screen, &rect);
}

void Projectile::tick() {
	rect.x += speedX;
	rect.y += speedY;
	
	if (rect.x > 890 || rect.x < 0 || rect.y > 790 || rect.y < 0) {
		delete this;
	}
}

int Projectile::getDamage() {
	return damage;
}

