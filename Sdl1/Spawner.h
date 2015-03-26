#ifndef SPAWNER_H
#define SPAWNER_H

#include "Sprite.h"
#include <time.h>
#include "Projectile.h"
#include <vector>
#include "SDL_timer.h"
#include "SDL.h"
#include "Tower.h"

class Spawner : public gameEngine::Sprite {
public:
	static Spawner* getInstance();
	~Spawner();
	void draw();
	void tick();
	void start();
private:
	Spawner();
	Uint32 startTimer;
	bool started;
	int enemiesSpawned;
};

#endif