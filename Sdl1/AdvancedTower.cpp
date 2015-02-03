#include "AdvancedTower.h"
#include "BasicTower.h"
#include "Projectile.h"
#include "Spawner.h"
#include "GameEngine.h"
#include "Tower.h"

#include "GameHandler.h"

using namespace gameEngine;

AdvancedTower::AdvancedTower(int x, int y, int w, int h) : 
Tower(x, y, w, h, "../images/advanced_tower.bmp")
{
	goldCost = 10;
}

void AdvancedTower::mouseDown(int x, int y) {
	gh.addProjectile(new Projectile(rect.x, rect.y, x, y, 10, 10, 2, 10, 
		"../images/projectile_adv.bmp"));
}

void AdvancedTower::mousePressed(int x, int y) {
	gh.addProjectile(new Projectile(rect.x, rect.y, x, y, 10, 10, 2, 10,
		"../images/projectile_adv.bmp"));
}

void AdvancedTower::tick() {

}

AdvancedTower::~AdvancedTower()
{
}
