#include "AdvancedTower.h"
#include "BasicTower.h"
#include "Projectile.h"
#include "Spawner.h"
#include "GameEngine.h"
#include "Tower.h"

using namespace gameEngine;

AdvancedTower::AdvancedTower(int x, int y, int w, int h) : Tower(x, y, w, h)
{
	goldCost = 10;
	image = SDL_DisplayFormat(SDL_LoadBMP("../images/advanced_tower.bmp"));
	Uint32 transp = *(Uint32*)image->pixels;
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
}

void AdvancedTower::mouseDown(int x, int y) {
	
		Projectile* projectile = new Projectile(rect.x, rect.y, x, y, 10, 10, 2, 10, "../images/projectile_adv.bmp");
		ga.add(projectile);
		Spawner::projectiles.push_back(projectile);
	
}

void AdvancedTower::tick() {

}


AdvancedTower::~AdvancedTower()
{
}
