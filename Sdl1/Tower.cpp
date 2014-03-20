#include "Tower.h"
#include "Globals.h"
#include <SDL.h>
#include "Projectile.h"
#include "GameEngine.h"
#include "Spawner.h"

using namespace gameEngine;

Tower::Tower(int x, int y, int w, int h) : Sprite(x, y, w, h) {
	image = SDL_DisplayFormat(SDL_LoadBMP("C:/users/Jonathan/Pictures/Prog3 spel/tower.bmp"));
	Uint32 transp = *(Uint32*)image->pixels;
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
}

void Tower::draw() {
	SDL_BlitSurface(image, NULL, sys.screen, &rect);
}

void Tower::tick() {
	
}

void Tower::mouseDown(int x, int y) {
	Projectile* projectile = new Projectile(rect.x, rect.y, 10, 10);
	ga.add(projectile);
	Spawner::projectiles.push_back(projectile);
	projectile->setTarget(x, y);
}

Tower::~Tower(void)
{
}
