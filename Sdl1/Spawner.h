#ifndef SPAWNER_H
#define SPAWNER_H

#include "Sprite.h"
#include <time.h>
#include "Projectile.h"
#include <vector>
#include "SDL_timer.h"
#include "SDL.h"
#include "Tower.h"

/* A singleton that handles spawning of enemies. */
class Spawner : public gameEngine::Sprite {
public:
	static Spawner* getInstance();
	~Spawner();
	void draw();
	void tick();
	
	/* Starts a timer during which enemies will be spawned. */
	void start();
private:
	Spawner();

	/* The amount of ticks that have elapsed when the spawner is set to 
	start */
	Uint32 begin;

	bool started;

	/* Keeps track of the number of enemies spawned. */
	int enemiesSpawned;
};

#endif