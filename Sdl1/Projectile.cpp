#include "Projectile.h"
#include "Globals.h"
#include "Tower.h"

using namespace gameEngine;

Projectile::Projectile(int x, int y, int w, int h) : Sprite(x, y, w, h)
{
	image = SDL_DisplayFormat(SDL_LoadBMP("../images/projectile.bmp"));
	Uint32 transp = *(Uint32*)image->pixels;
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
	towerX = x;
	towerY = y;
}


Projectile::~Projectile(void)
{
}


void Projectile::draw() {
	SDL_BlitSurface(image, NULL, sys.screen, &rect);
}

void Projectile::tick() {
	if (yTarget - towerY > xTarget - towerX) {
		rect.y++;

		if (rect.y % yRatio == 0) {
			rect.x++;
		}
	}

	if (xTarget > yTarget) {
		rect.x++;

		if (yTarget - rect.y > 0 && rect.x % xRatio == 0) {
			rect.y++;
		} else if (yTarget - rect.y < 0 && rect.x % xRatio == 0) {
			rect.y--;
		}
	}
	
	if (xTarget - rect.x == 0 && yTarget - rect.y == 0) {
		//delete this;
	}
}

void Projectile::setTarget(int x, int y) {
	xTarget = x;
	yTarget = y;
	yRatio = y - towerY / x - towerX;
	xRatio = x - towerX / y - towerY;
}