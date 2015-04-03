#include "BasicTower.h"

const int BasicTower::goldCost = 5;

BasicTower::BasicTower(int x, int y, int w, int h) : 
Tower(x, y, w, h, "../images/basic_tower.bmp", "../images/projectile.bmp")
{
	damage = 1;
	speed = 2;
}

BasicTower::~BasicTower()
{
}

