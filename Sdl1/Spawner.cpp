#include "Spawner.h"
#include "GameEngine.h"
#include "Enemy.h"
#include <vector>
#include <iostream>
#include "SDL_timer.h"
#include <algorithm>
#include "Rect.h"
#include "GameHandler.h"

using namespace gameEngine;

Spawner::Spawner() : enemiesSpawned(0) {
}

Spawner* Spawner::getInstance() {
	static Spawner spawner;
	return &spawner;
}

Spawner::~Spawner() {

}

void Spawner::draw() {

}

void Spawner::start() {
	if (started) {
		return;
	}

	started = true;
	startTimer = SDL_GetTicks();
	gh.setNextLevel();
	Enemy::setValue(gh.getLevel() * 2);
}

void Spawner::tick() {

	if (started) {
		Uint32 end = SDL_GetTicks();
		Uint32 elapsed = end - startTimer;

		// Spawns a new enemy every second until 5 enemies have been spawned
		if (elapsed > 1000) {
			ge().add(new Enemy(gh.checkpoints[0].x, gh.checkpoints[0].y, 32, 32));
			startTimer = end;
			enemiesSpawned++;
		}
		if (enemiesSpawned > 4) {
			started = false;
			enemiesSpawned = 0;
		}
	}
}
