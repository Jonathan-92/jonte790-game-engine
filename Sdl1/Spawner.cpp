#include "Spawner.h"
#include "GameEngine.h"
#include "Enemy.h"
#include "Tower.h"
#include "Globals.h"
#include <vector>
#include <iostream>
#include "SDL_timer.h"
#include <algorithm>
#include "BasicTower.h"
#include "AdvancedTower.h"
#include "Rect.h"

using namespace gameEngine;

Spawner::Spawner() : Sprite(0, 0, 0, 0) {
	imageBasicTower = SDL_DisplayFormat(SDL_LoadBMP("../images/basic_tower.bmp"));
	Uint32 transp = *(Uint32*)imageBasicTower->pixels;
	SDL_SetColorKey(imageBasicTower, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);

	imageAdvancedTower = SDL_DisplayFormat(SDL_LoadBMP("../images/advanced_tower.bmp"));
	Uint32 transp2 = *(Uint32*)imageAdvancedTower->pixels;
	SDL_SetColorKey(imageAdvancedTower, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp2);

}

Spawner::~Spawner(void) {
}

void Spawner::draw() {

	int x, y;
	SDL_GetMouseState(&x, &y);

	if ((x < 350 || x > 500) && y < 650) {
		rect.setRect(x, y, 32, 32);

		if (buildingBasicTower) {
			SDL_BlitSurface(imageBasicTower, NULL, sys.screen, &rect);
		}
		else if (buildingAdvancedTower) {
			SDL_BlitSurface(imageAdvancedTower, NULL, sys.screen, &rect);
		}
	}
}

bool Spawner::started;
bool Spawner::buildingBasicTower;
bool Spawner::buildingAdvancedTower;
int Spawner::lives = 10;
int Spawner::level = 0;
int Spawner::gold = 5;
int Spawner::times = 0;
unsigned int Spawner::building_tower = 0U;
Uint32 Spawner::startTimer;
std::vector<Projectile*> Spawner::projectiles;
std::vector<Tower*> Spawner::towers;

void Spawner::start() {
	if (started) {
		return;
	}

	started = true;
	startTimer = SDL_GetTicks();
	level += 1;
	Enemy::setValue(pow(level, 2) / 2 + 1);
}

void Spawner::mouseDown(int x, int y) {
	if ((x < 350 || x > 500) && y < 650) {
		
		Tower* t;

		if (BUILDING_BASIC & building_tower && gold >= BasicTower::getGoldCost()) {
			t = new BasicTower(x, y, 32, 32);

			// If the new tower overlaps another tower, don't place it
			if (towerOverlaps(t)) {
				return;
			}

			building_tower = 0U;
			Spawner::gold -= BasicTower::getGoldCost();
		}
		else if (BUILDING_ADVANCED & building_tower && gold >= AdvancedTower::getGoldCost()) {
			t = new AdvancedTower(x, y, 32, 32);

			// If the new tower overlaps another tower, don't place it
			if (towerOverlaps(t)) {
				return;
			}

			building_tower = 0U;
			Spawner::gold -= AdvancedTower::getGoldCost();
		}
		else {
			building_tower & 0U;
			return;
		}

		towers.push_back(t);
		ga.add(t);
		
	}
	else {
		building_tower & 0U;
	}

}

bool Spawner::towerOverlaps(Tower* t) {
	for (std::vector<Tower*>::iterator it = towers.begin(); it != towers.end(); it++) {
		if (t->rect.overlaps((*it)->rect)) {
			return true;
		}
	}
}

void Spawner::removeProjectile(Projectile* p) {
	projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), p), projectiles.end());
}

void Spawner::tick() {

	if (started) {
		Uint32 end = SDL_GetTicks();
		Uint32 elapsed = end - startTimer;

		 //Spawns a new enemy every second
		if (elapsed > 1000) {
			ga.add(new Enemy(430, 0, 32, 32));
			startTimer = end;
			times++;
		}

		if (times > 5) {
			started = false;
			times = 0;
		}
	}
}
