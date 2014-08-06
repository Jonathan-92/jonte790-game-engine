#ifndef SPAWNER_H
#define SPAWNER_H

#define BUILDING_BASIC		0x00000001U
#define BUILDING_ADVANCED	0x00000002U

#include "Sprite.h"
#include <time.h>
#include "Projectile.h"
#include <vector>
#include "SDL_timer.h"

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
	static std::vector<Tower*> towers;
	static int lives;
	static int level;
	static int gold;
	static void removeProjectile(Projectile* p);
	static bool buildingBasicTower;
	static bool buildingAdvancedTower;
	static unsigned int building_tower;
private:
	SDL_Surface* imageBasicTower;
	SDL_Surface* imageAdvancedTower;
	bool towerOverlaps(Tower* t);
	static SDL_TimerID myTimerID;
	static Uint32 startTimer;
	static bool started;
	static int times;
};

#endif