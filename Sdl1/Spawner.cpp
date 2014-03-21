#include "Spawner.h"
#include "GameEngine.h"
#include "Enemy.h"
#include "Tower.h"
#include "Globals.h"

using namespace gameEngine;

Spawner::Spawner() : Sprite(40, 40, 30, 30) {
	image = SDL_DisplayFormat(SDL_LoadBMP("../images/tower.bmp"));
	Uint32 transp = *(Uint32*)image->pixels;
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
}

Spawner::~Spawner(void) {
}

void Spawner::draw() {

}

bool Spawner::started;
bool Spawner::buildingTower = false;
Uint32 Spawner::startTimer;
std::vector<Projectile*> Spawner::projectiles;

void Spawner::start() {
	started = true;
	startTimer = SDL_GetTicks();
}

void Spawner::enableBuilding() {
	buildingTower = true;
}

void Spawner::mouseDown(int x, int y) {
	if (buildingTower && (x < 350 || x > 500) && y < 650) {
		std::vector<Sprite*> sprites = ga.getSprites();
		Tower* t = new Tower(x, y, 32, 32);

		// If the new tower overlaps another tower, don't place it
		for (std::vector<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); it++) {
			if (dynamic_cast<Tower*>(*it) && (*it)->rect.overlaps(t->rect)) {
				return;
			}
		}

		ga.add(t);
		buildingTower = false;
	}

	if (y > 650) {
		buildingTower = false;
	}

}

void Spawner::tick() {
	if (buildingTower) {
		SDL_BlitSurface(image, NULL, sys.screen, &rect);
	}

	if (started) {
		Uint32 end = SDL_GetTicks();
		Uint32 elapsed = end - startTimer;

		// Spawns a new enemy every 5 seconds
		if (elapsed % 500 == 0) {
			ga.add(new Enemy(430, 0, 32, 32));
		}

		if (elapsed > 10000)
			started = false;
	}
}