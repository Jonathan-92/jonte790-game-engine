#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "Checkpoint.h"
#include <vector>
#include "Projectile.h"


//Stores values and objects related to the game and makes them 
//globally available to other classes in the game, with certain
//restrictions
class GameHandler
{
public:
	GameHandler();
	static const Checkpoint checkpoints[5];
	static std::vector<Projectile*> projectiles;
	int gold;
	int getLives();
	int getLevel();
	void decreaseLives(int amount);
	void setNextLevel();
	void addProjectile(Projectile* projectile);
	void removeProjectile(Projectile* p);
	~GameHandler();
private:
	int lives;
	int level;
};

extern GameHandler gh;

#endif