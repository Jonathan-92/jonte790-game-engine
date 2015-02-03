#include "Tower.h"

#include <SDL.h>
#include "GameEngine.h"
#include "Spawner.h"
#include "GameHandler.h"
#include <string>

using namespace gameEngine;

Tower::Tower(int x, int y, int w, int h, std::string imgPath) :
Sprite(x, y, w, h, imgPath)
{

}

int Tower::getGoldCost() {
	return goldCost;
}

Tower::~Tower(void)
{
}
