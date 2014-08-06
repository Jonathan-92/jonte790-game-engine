#include "Tower.h"
#include "Globals.h"
#include <SDL.h>
#include "Projectile.h"
#include "GameEngine.h"
#include "Spawner.h"

using namespace gameEngine;

Tower::Tower(int x, int y, int w, int h) : Sprite(x, y, w, h) {
	
}

int Tower::goldCost;

void Tower::draw() {
	SDL_BlitSurface(image, NULL, sys.screen, &rect);
}

void Tower::tick() {

}

void Tower::mouseDown(int x, int y) {

}

int Tower::getGoldCost() {
	return goldCost;
}

Tower::~Tower(void)
{
}
