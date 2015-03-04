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
}

//const int Tower::goldCost = 0;

void Tower::mouseDown(int x, int y) {
	gh.addProjectile(new Projectile(this, x, y));
}

void Tower::mousePressed(int x, int y) {
	gh.addProjectile(new Projectile(this, x, y));
}

Tower::~Tower(void)
{
}
