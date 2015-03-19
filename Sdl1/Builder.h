#ifndef BUILDER_H
#define BUILDER_H

#define BUILDING_BASIC		0x00000001U
#define BUILDING_ADVANCED	0x00000002U

#include "Sprite.h"
#include <vector>
#include "Tower.h"
#include "Rect.h"

class Builder : public gameEngine::Sprite
{
public:
	static Builder* getInstance();
	std::vector<Tower*> towers;
	bool buildingBasicTower;
	bool buildingAdvancedTower;
	unsigned int building_tower;
	void enableBuilding();
	void draw();
	void tick();
	void mouseDown(int x, int y);
	void keyDown(SDL_Event& eve); 
	~Builder();
	Builder();
private:
	// Length of tower texture
	const int towerS;
	// Texture of BasicTower
	SDL_Texture* basicTexture;
	// Texture of AdvancedTower
	SDL_Texture* advancedTexture;
	// Help-function to set the texture of a tower
	SDL_Texture* setTexture(SDL_Surface* surface);
	// Checks whether the mouse pointer is within an area which a tower can be 
	// built on
	const bool withinBuildableArea(int x, int y) const;
	const int centered(int p) const;
	const bool overlapsTower(gameEngine::Rect rect) const;
};

#endif