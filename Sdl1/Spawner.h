#ifndef SPAWNER_H
#define SPAWNER_H
#include "Sprite.h"
#include <time.h>
#include "Projectile.h"
#include <vector>

class Spawner : public gameEngine::Sprite {
public:
	Spawner();
	~Spawner(void);
	void draw();
	void tick();
	void mouseDown(int x, int y);
	static void start();
	static void enableBuilding();
	static std::vector<Projectile*> projectiles;
private:
	static Uint32 startTimer;
	static bool started;
	static bool buildingTower;
};

#endif