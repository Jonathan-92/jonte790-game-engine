#include "BasicTower.h"
#include "Projectile.h"
#include "Spawner.h"
#include "GameEngine.h"
#include "Tower.h"

using namespace gameEngine;

BasicTower::BasicTower(int x, int y, int w, int h) : Tower(x, y, w, h)
{
	goldCost = 5;
	image = SDL_DisplayFormat(SDL_LoadBMP("../images/basic_tower.bmp"));
	Uint32 transp = *(Uint32*)image->pixels;
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
}

void BasicTower::mouseDown(int x, int y) {
	
		Projectile* projectile = new Projectile(rect.x, rect.y, x, y, 10, 10, 1, 5, "../images/projectile.bmp");
		ga.add(projectile);
		Spawner::projectiles.push_back(projectile);
	
}

void BasicTower::tick() {

}

BasicTower::~BasicTower()
{
}
