#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "Checkpoint.h"
#include <vector>
#include "Projectile.h"

class GameHandler
{
public:
	GameHandler();
	//static GameHandler* getInstance();
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