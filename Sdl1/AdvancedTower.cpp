#include "AdvancedTower.h"

const int AdvancedTower::goldCost = 10;

AdvancedTower::AdvancedTower(int x, int y, int w, int h) : 
	Tower(x, y, w, h, "../images/advanced_tower.bmp", 
	"../images/projectile_adv.bmp")
{
	damage = 2;
	speed = 4;
}

AdvancedTower::~AdvancedTower()
{
}
