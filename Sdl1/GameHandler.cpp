#include "GameHandler.h"
#include <string>
#include "GameEngine.h"
#include <vector>
#include <algorithm>

using namespace gameEngine;

GameHandler::GameHandler() : lives(10), level(0), gold(8)
{
}

//GameHandler* GameHandler::getInstance()
//{
//	static GameHandler gh;
//	return &gh;
//}

std::vector<Projectile*> GameHandler::projectiles;
const Checkpoint GameHandler::checkpoints[5] = {
	Checkpoint(-50, 150),
	Checkpoint(650, 150),
	Checkpoint(650, 350),
	Checkpoint(350, 350),
	Checkpoint(350, 684)
};

void GameHandler::addProjectile(Projectile* projectile) {
	ga.add(projectile);
	projectiles.push_back(projectile);
}

void GameHandler::removeProjectile(Projectile* p) {
	projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), p), 
		projectiles.end());
}

int GameHandler::getLives()
{
	return lives;
}

int GameHandler::getLevel()
{
	return level;
}

void GameHandler::decreaseLives(int amount) 
{
	lives -= amount;
}

void GameHandler::setNextLevel() 
{
	++level;
}

GameHandler::~GameHandler()
{
}

GameHandler gh;