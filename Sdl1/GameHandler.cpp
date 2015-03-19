

#include "GameHandler.h"
#include <string>
#include "GameEngine.h"
#include <vector>
#include <algorithm>
#include "Label.h"

using namespace gameEngine;

GameHandler::GameHandler() : lives(10), level(0), gold(8)
{
}

const Checkpoint GameHandler::checkpoints[5] = {
	Checkpoint(-50, 150),
	Checkpoint(650, 150),
	Checkpoint(650, 350),
	Checkpoint(350, 350),
	Checkpoint(350, 684)
};

void GameHandler::addProjectile(Projectile* projectile) {
	ge().add(projectile);
	projectiles.push_back(projectile);
}

void GameHandler::removeProjectile(Projectile* p) {
	projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), p), 
		projectiles.end());
}

int GameHandler::getGold() const {
	return gold;
}

int GameHandler::getLives() const
{
	return lives;
}

int GameHandler::getLevel() const
{
	return level;
}

void GameHandler::decreaseGold(int amount) {
	gold -= amount;
}

void GameHandler::increaseGold(int amount) {
	gold += amount;
}

void GameHandler::decreaseLives(int amount) 
{
	if ((lives -= amount) < 1) {
		Label* loseMsg = Label::getInstance(500, 500, 100, 40, "You lost");
		ge().add(loseMsg);
		startButton->disable();
	}
}

void GameHandler::setNextLevel() 
{
	++level;
}

GameHandler::~GameHandler()
{
}

GameHandler gh;