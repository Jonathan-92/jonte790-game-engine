#include "Builder.h"
#include "GameEngine.h"
#include "Tower.h"
#include "BasicTower.h"
#include "AdvancedTower.h"
#include "GameHandler.h"
#include "Rect.h"

using namespace gameEngine;

const int Builder::towerS = 50;

Builder::Builder()
{
	SDL_Surface* basicSurface = SDL_LoadBMP("../images/basic_tower.bmp");
	if (basicSurface == nullptr)
		gameEngine::throwException("image is null", SDL_GetError);
	basicTexture = setTexture(basicSurface);
	SDL_FreeSurface(basicSurface);

	SDL_Surface* advancedSurface = SDL_LoadBMP("../images/advanced_tower.bmp");
	advancedTexture = setTexture(advancedSurface);
	if (advancedSurface == nullptr)
		gameEngine::throwException("image is null", SDL_GetError);
	SDL_FreeSurface(advancedSurface);
}

SDL_Texture* Builder::setTexture(SDL_Surface* surface) {
	Uint32 transp = *(Uint32*)surface->pixels;
	SDL_SetColorKey(surface, SDL_RLEACCEL, transp);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(ge().getRenderer(), surface);
	if (texture == nullptr)
		gameEngine::throwException("CreateTextureFromSurface failed: %s\n", SDL_GetError);

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

int Builder::centered(int p) const {
	return p - towerS / 2;
}

void Builder::tick() {
	int x, y;
	SDL_GetMouseState(&x, &y);

	if (withinBuildableArea(x, y)) {
		Rect rect(centered(x), centered(y), towerS, towerS);

		if (buildingBasic()) {
			SDL_RenderCopy(ge().getRenderer(), basicTexture, nullptr, &rect);
		}
		else if (buildingAdvanced()) {
			SDL_RenderCopy(ge().getRenderer(), advancedTexture, nullptr, &rect);
		}
	}
}

bool Builder::withinBuildableArea(int x, int y) const {
	Rect rect(centered(x), centered(y), towerS, towerS);
	return (y < 75 || x > 725 || (x > 425 && y > 425) || (x < 275 && y > 225) ||
		(x < 575 && y > 225 && y < 275)) && y < 675 && y > 25 && x > 25 && x < 875 &&
		!overlapsTower(rect);
}

bool Builder::buildingBasic() const {
	return BUILDING_BASIC & building_tower;
}

bool Builder::buildingAdvanced() const {
	return BUILDING_ADVANCED & building_tower;
}

void Builder::mouseDown(int x, int y) {
	if (building_tower && withinBuildableArea(x, y)) {
		Rect rect(centered(x), centered(y), towerS, towerS);

		if (overlapsTower(rect))
			return;

		Tower* t;

		if (buildingBasic()) {
			t = new BasicTower(rect.x, rect.y, rect.w, rect.h);

			building_tower = 0U; // Tower placed. Reset bit-mask. 
			gh.decreaseGold(BasicTower::goldCost);
		}
		else if (buildingAdvanced()) {
			t = new AdvancedTower(rect.x, rect.y, rect.w, rect.h);

			building_tower = 0U; // Tower placed. Reset bit-mask. 
			gh.decreaseGold(AdvancedTower::goldCost);
		}
		else {
			building_tower = 0U;
			delete t;
			return;
		}

		towers.push_back(t);
		ge().add(t);
	}
	else {
		building_tower = 0U;
	}
}


/* Sets the bit-mask building_tower to either the value of BUILDING_BASIC
or BUILDING_ADVANCED if Q och W is pressed. */
void Builder::keyDown(SDL_Event& eve) {
	if (eve.key.keysym.sym == SDLK_q) {
		enableBuilding(BasicTower::goldCost, BUILDING_BASIC);
	}
	else if (eve.key.keysym.sym == SDLK_w) {
		enableBuilding(AdvancedTower::goldCost, BUILDING_ADVANCED);
	}
}

void Builder::enableBuilding(int goldCost, int towerMask) {
	if (gh.affords(goldCost)) {
		building_tower &= 0U;
		building_tower |= towerMask;
	}
}

bool Builder::overlapsTower(Rect rect) const {
	for (std::vector<Tower*>::const_iterator it = towers.begin(); it != towers.end(); it++) {
		if (rect.overlaps((*it)->rect)) {
			return true;
		}
	}

	return false;
}
