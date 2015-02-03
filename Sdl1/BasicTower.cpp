#include "BasicTower.h"
#include "Projectile.h"
#include "Spawner.h"
#include "GameEngine.h"
#include "Tower.h"

#include "GameHandler.h"

using namespace gameEngine;

BasicTower::BasicTower(int x, int y, int w, int h) : 
Tower(x, y, w, h, "../images/basic_tower.bmp")
{
	goldCost = 5;
}

void BasicTower::mouseDown(int x, int y) {
	Projectile* projectile = new Projectile(rect.x, rect.y, x, y, 10, 10, 1, 5, "../images/projectile.bmp");
	ga.add(projectile);
	gh.projectiles.push_back(projectile);
}

void BasicTower::tick() {

}

BasicTower::~BasicTower()
{
}
