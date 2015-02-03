#include "Builder.h"
#include "GameEngine.h"
#include "Tower.h"
#include "BasicTower.h"
#include "AdvancedTower.h"
#include "GameHandler.h"

using namespace gameEngine;

Builder::Builder()
{
	SDL_Surface* basicSurface = SDL_LoadBMP("../images/basic_tower.bmp");
	SDL_Surface* advancedSurface = SDL_LoadBMP("../images/advanced_tower.bmp");
	basicTexture = setTexture(basicSurface);
	advancedTexture = setTexture(advancedSurface);
	SDL_FreeSurface(basicSurface);
	SDL_FreeSurface(advancedSurface);
}

SDL_Texture* Builder::setTexture(SDL_Surface* surface) {
	Uint32 transp = *(Uint32*)surface->pixels;
	SDL_SetColorKey(surface, SDL_RLEACCEL, transp);
	return SDL_CreateTextureFromSurface(ga.getRenderer(), surface);
}

Builder::~Builder()
{
}

Builder* Builder::getInstance() {
	static Builder builder;
	return &builder;
}

void Builder::draw() {
	int x = 0, y = 0;
	SDL_GetMouseState(&x, &y);

	if ((y < 66 || x > 700 || (x > 400 && y > 400) || (x < 266 && y > 200) ||
		(x > 300 && x < 566 && y > 200 && y < 266)) && y < 670) {
		rect.setRect(x, y, 32, 32);

		if (BUILDING_BASIC & building_tower) {
			SDL_RenderCopy(ga.getRenderer(), basicTexture, nullptr, &rect);
		}
		else if (BUILDING_ADVANCED & building_tower) {
			SDL_RenderCopy(ga.getRenderer(), advancedTexture, nullptr, &rect);
		}
	}
}

void Builder::tick() {

}

void Builder::mouseDown(int x, int y) {
	if ((y < 66 || x > 700 || (x > 400 && y > 400) || (x < 266 && y > 200) ||
		(x > 300 && x < 566 && y > 200 && y < 266)) && y < 670) {

		Tower* t;

		if (BUILDING_BASIC & building_tower && gh.gold >= BasicTower::getGoldCost()) {
			t = new BasicTower(x, y, 32, 32);

			// If the new tower overlaps another tower, don't place it
			if (towerOverlaps(t)) {
				return;
			}

			building_tower = 0U;
			gh.gold -= BasicTower::getGoldCost();
		}
		else if (BUILDING_ADVANCED & building_tower && gh.gold >= AdvancedTower::getGoldCost()) {
			t = new AdvancedTower(x, y, 32, 32);

			// If the new tower overlaps another tower, don't place it
			if (towerOverlaps(t)) {
				return;
			}

			building_tower = 0U;
			gh.gold -= AdvancedTower::getGoldCost();
		}
		else {
			building_tower = 0U;
			return;
		}

		towers.push_back(t);
		ga.add(t);

	}
	else {
		building_tower = 0U;
	}
}

void Builder::keyDown(SDL_Event& eve) {
	if (eve.key.keysym.sym == SDLK_q) {
		building_tower &= 0U;
		building_tower |= BUILDING_BASIC;
	}
	else if (eve.key.keysym.sym == SDLK_w) {
		building_tower &= 0U;
		building_tower |= BUILDING_ADVANCED;
	}
}

bool Builder::towerOverlaps(Tower* t) {
	for (std::vector<Tower*>::iterator it = towers.begin(); it != towers.end(); it++) {
		if (t->rect.overlaps((*it)->rect)) {
			return true;
		}
	}

	return false;
}
