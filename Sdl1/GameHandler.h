#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "Checkpoint.h"
#include <vector>
#include "Projectile.h"
#include "G_Button.h"


//Stores values and objects related to the game and makes them 
//globally available to other classes in the game, with certain
//restrictions
class GameHandler
{
public:
	GameHandler();
	static const Checkpoint checkpoints[5];
	std::vector<Projectile*> projectiles;
	int getGold() const;
	int getLives() const;
	int getLevel() const;
	void decreaseGold(int amount);
	void increaseGold(int amount);
	void decreaseLives(int amount);
	void setNextLevel();
	void addProjectile(Projectile* projectile);
	void removeProjectile(Projectile* p);
	~GameHandler();
	gameEngine::G_Button* startButton;
private:
	int gold;
	int lives;
	int level;
};

extern GameHandler gh;

#endif