#include "Tower.h"

#include <SDL.h>
#include "GameEngine.h"
#include "Spawner.h"
#include "GameHandler.h"
#include <string>

using namespace gameEngine;

Tower::Tower(int x, int y, int w, int h, std::string imgPath, 
	std::string projImage) : Sprite(x, y, w, h, imgPath, true), projImage(projImage)
{
	startTimer = SDL_GetTicks();
}

Tower::~Tower(void)
{
}

void Tower::mousePressed(int x, int y) {
	Uint32 end = SDL_GetTicks();
	Uint32 elapsed = end - startTimer;

	if (elapsed > 150) {
		gh.addProjectile(new Projectile(this, x, y));
		startTimer = end;
	}
}

int Tower::getDamage() const {
	return damage;
}

int Tower::getSpeed() const {
	return speed;
}