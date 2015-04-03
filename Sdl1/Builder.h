#ifndef BUILDER_H
#define BUILDER_H

/* A bit-manipulation flag that determines if a Basic Tower is currenyl being
placed */
#define BUILDING_BASIC		0x00000001U

/* A bit-manipulation flag that determines if a Advanced Tower is currently 
being placed */
#define BUILDING_ADVANCED	0x00000002U

#include "Sprite.h"
#include <vector>
#include "Tower.h"
#include "Rect.h"

/* A singleton that handles placing of Towers. */
class Builder : public gameEngine::Sprite
{
public:
	static Builder* getInstance();
	Builder();
	~Builder();

	void draw(); // Inherited from Sprite

	/* Inherited from Sprite. This implementation draws the Tower currently 
	being placed at the mouse position. */
	void tick();

	/* Inherited from Sprite. This implementation places a Tower a the mouse
	position if certain conditions are fulfilled. */
	void mouseDown(int x, int y);
	
	/* Inherited from Sprite. This implementation starts enables building
	of a Tower when a key is pressed. */
	void keyDown(SDL_Event& eve);

	void enableBuilding(int goldCost, int towerMask);
private:
	// Length of tower texture
	static const int towerS;

	// Checks whether the mouse pointer is within an area which a tower can be 
	// built on
	bool withinBuildableArea(int x, int y) const;

	/* Returns a coordinate that is relative to the mouse position and the
	side of the Tower so that the Tower can be drawed at the right position. */
	int centered(int p) const;

	/* Checks if a rect overlaps an already existing tower. */
	bool overlapsTower(gameEngine::Rect rect) const;

	/* Checks if a Basic Tower has been chosen for placement */
	bool buildingBasic() const;

	/* Checks if a Advanced Tower has been chosen for placement */
	bool buildingAdvanced() const;

	// Help-function to set the texture of a tower
	SDL_Texture* setTexture(SDL_Surface* surface);

	// Texture of BasicTower
	SDL_Texture* basicTexture;

	// Texture of AdvancedTower
	SDL_Texture* advancedTexture;

	/* Stores all the Towers that are present in the game. */
	std::vector<Tower*> towers;
	
	/* A bit-mask which is used in conjunction with the two macros defined
	in the beginning of the file to determine if a Basic Tower or Advanced
	Tower is being placed. */
	unsigned int building_tower;
};

#endif