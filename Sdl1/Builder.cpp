#include "Builder.h"
#include "GameEngine.h"
#include "Tower.h"
#include "BasicTower.h"
#include "AdvancedTower.h"
#include "GameHandler.h"
#include "Rect.h"

using namespace gameEngine;

Builder::Builder() : towerS(50)
{
	SDL_Surface* basicSurface = SDL_LoadBMP("../images/basic_tower.bmp");
	if (basicSurface == nullptr)
		throw std::runtime_error("image is null"); 
	basicTexture = setTexture(basicSurface);
	SDL_FreeSurface(basicSurface);

	SDL_Surface* advancedSurface = SDL_LoadBMP("../images/advanced_tower.bmp");
	advancedTexture = setTexture(advancedSurface);
	if (advancedSurface == nullptr)
		throw std::runtime_error("image is null");
	SDL_FreeSurface(advancedSurface);
}

SDL_Texture* Builder::setTexture(SDL_Surface* surface) {
	Uint32 transp = *(Uint32*)surface->pixels;
	SDL_SetColorKey(surface, SDL_RLEACCEL, transp);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(ge().getRenderer(), surface);
	if (texture == nullptr) {
		fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
	}

	return texture;
}

Builder::~Builder()
{
	SDL_DestroyTexture(basicTexture);
	SDL_DestroyTexture(advancedTexture);
	for (std::vector<Tower*>::iterator it = towers.begin(); 
		it != towers.end(); it++) {
		delete *it;
	}
}

Builder* Builder::getInstance() {
	static Builder builder;
	return &builder;
}

void Builder::draw() {
	
}

const int Builder::centered(int p) const {
	return p - towerS / 2;
}

void Builder::tick() {
	int x, y;
	SDL_GetMouseState(&x, &y);

	if (withinBuildableArea(x, y)) {
		Rect rect(centered(x), centered(y), towerS, towerS);

		if (BUILDING_BASIC & building_tower) {
			SDL_RenderCopy(ge().getRenderer(), basicTexture, nullptr, &rect);
		}
		else if (BUILDING_ADVANCED & building_tower) {
			SDL_RenderCopy(ge().getRenderer(), advancedTexture, nullptr, &rect);
		}
	}
}

const bool Builder::withinBuildableArea(int x, int y) const {
	Rect rect(centered(x), centered(y), towerS, towerS);
	return (y < 75 || x > 725 || (x > 425 && y > 425) || (x < 275 && y > 225) ||
		(x < 575 && y > 225 && y < 275)) && y < 675 && y > 25 && x > 25 && x < 875 &&
		!overlapsTower(rect);
}

void Builder::mouseDown(int x, int y) {
	if (withinBuildableArea(x, y)) {

		Tower* t;

		if (BUILDING_BASIC & building_tower && gh.gold >= BasicTower::goldCost) {
			t = new BasicTower(centered(x), centered(y), towerS, towerS);

			// If the new tower overlaps another tower, don't place it
			if (overlapsTower(t->rect)) {
				delete t;
				return;
			}

			building_tower = 0U;
			gh.gold -= BasicTower::goldCost;
		}
		else if (BUILDING_ADVANCED & building_tower && gh.gold >= AdvancedTower::goldCost) {
			t = new AdvancedTower(centered(x), centered(y), towerS, towerS);

			// If the new tower overlaps another tower, don't place it
			if (overlapsTower(t->rect)) {
				delete t; 
				return;
			}

			building_tower = 0U;
			gh.gold -= AdvancedTower::goldCost;
		}
		else {
			building_tower = 0U;
			return;
		}

		towers.push_back(t);
		ge().add(t);

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

const bool Builder::overlapsTower(Rect rect) const {
	for (std::vector<Tower*>::const_iterator it = towers.begin(); it != towers.end(); it++) {
		if (rect.overlaps((*it)->rect)) {
			return true;
		}
	}

	return false;
}
