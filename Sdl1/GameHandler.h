#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "Checkpoint.h"
#include <vector>
#include "Projectile.h"
#include "G_Button.h"
#include "Enemy.h"

//Stores values and objects related to the game and makes them 
//globally available to other classes in the game, with certain
//restrictions
class GameHandler
{
public:
	// The checkpoints which spawned enemies will walk through
	static const Checkpoint checkpoints[5];
	
	GameHandler();
	~GameHandler();

	int getGold() const;
	int getLives() const;
	int getLevel() const;

	// Decreases gold by specified amount
	void decreaseGold(int amount);

	// Increases gold by speficied amount
	void increaseGold(int amount);

	// Decreases lives by amount. If lives == 0, display lose message
	void decreaseLives(int amount);

	void setNextLevel();
	void addProjectile(Projectile* projectile);
	void removeProjectile(Projectile* projectile);
	bool affords(int goldCost);

	/* Checks whether any of the Projectiles in projectiles overlaps with an 
	enemy. If one Projectile does, that Projectile is returned, else nullptr*/
	Projectile* overlaps(Enemy* enemy);
private:
	// Keeps track of the current projectiles that have been fired
	std::vector<Projectile*> projectiles;
	
	gameEngine::G_Button* startButton;
	int gold;
	int lives;
	int level;
};

/* A global object is declared since the members of GameHandler will be used
in many other scopes */
extern GameHandler gh;

#endif