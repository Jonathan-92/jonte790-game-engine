#include "GameHandler.h"
#include <string>
#include "GameEngine.h"
#include <vector>
#include <algorithm>
#include "Label.h"
#include <sstream>
#include "Spawner.h"

using namespace gameEngine;
using namespace std;

Spawner* spawner;

void start() {
	spawner->start();
}

GameHandler::GameHandler() : lives(10), level(0), gold(8)
{
	spawner = Spawner::getInstance();
	ge().add(spawner);

	gh.startButton = new G_Button(5, 705, 90, 40, "../images/startButton.bmp", start);
	ge().add(gh.startButton);
}

GameHandler::~GameHandler()
{
}

const Checkpoint GameHandler::checkpoints[5] = {
	Checkpoint(-64, 150),
	Checkpoint(650, 150),
	Checkpoint(650, 350),
	Checkpoint(350, 350),
	Checkpoint(350, 684)
};

void GameHandler::addProjectile(Projectile* projectile) {
	ge().add(projectile);
	projectiles.push_back(projectile);
}

void GameHandler::removeProjectile(Projectile* projectile) {
	projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), projectile), 
		projectiles.end());
}

Projectile* GameHandler::overlaps(Enemy* enemy) {
	for (vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it) {
		if ((*it)->rect.overlaps(enemy->rect)) {
			return *it;
		}
	}

	return nullptr;
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
	/* If lives has reached 0, display lose message and prohibit the player 
	form continuing playing. */
	if ((lives -= amount) < 1) {
		string msg = "YOU LOST. You reached level: ";
		ostringstream os;
		os << msg << level;
		Label* loseMsg = Label::getInstance(500, 500, 300, 40, os.str());
		ge().add(loseMsg);
		startButton->disable();
	}
}

bool GameHandler::affords(int goldCost) {
	return gold >= goldCost;
}

void GameHandler::setNextLevel() 
{
	++level;
	Enemy::setValue(pow(level, 2) / 3 + 1);
}

GameHandler gh;