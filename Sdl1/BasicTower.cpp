#include "BasicTower.h"
#include "Projectile.h"
#include "Spawner.h"
#include "GameEngine.h"
#include "Tower.h"

#include "GameHandler.h"

using namespace gameEngine;

BasicTower::BasicTower(int x, int y, int w, int h) : 
Tower(x, y, w, h, "../images/basic_tower.bmp", "../images/projectile.bmp")
{
	damage = 1;
	speed = 2;
}

const int BasicTower::goldCost = 5;

void BasicTower::tick() {

}

BasicTower::~BasicTower()
{
}
