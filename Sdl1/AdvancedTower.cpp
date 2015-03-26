#include "AdvancedTower.h"
#include "BasicTower.h"
#include "Projectile.h"
#include "Spawner.h"
#include "GameEngine.h"
#include "Tower.h"
#include "GameHandler.h"

using namespace gameEngine;


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
