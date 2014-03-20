#include <SDL.h>
#include "GameEngine.h"
#include "Globals.h"
#include "Enemy.h"
#include "G_Button.h"
#include "Spawner.h"
#include <Windows.h>

using namespace gameEngine;

void quit() {
	exit(0);
}

void start() {
	Enemy::upHealth(5);
	Spawner::start();
}

void buildTower() {
	Spawner::enableBuilding();
}

int main(int argc, char** argv) {
	ga.setVideoMode(900, 800);
	ga.setBackground("C:/users/Jonathan/Pictures/Prog3 spel/map.bmp");
	ga.setFps(100);

	ga.add(new Enemy(50, 50, 32, 32));
	ga.add(new Spawner());

	G_Button* towerButton = new G_Button(105, 705, 50, 50, "C:/users/Jonathan/Pictures/Prog3 spel/tower.bmp", buildTower);
	ga.add(towerButton);

	G_Button* startButton = new G_Button(5, 705, 75, 25, "C:/users/Jonathan/Pictures/Prog3 spel/startButton.bmp", start);
	ga.add(startButton);

	G_Button* quitButton = new G_Button(5, 755, 75, 25, "C:/users/Jonathan/Pictures/Prog3 spel/quitButton.bmp", quit);
	ga.add(quitButton);

	ga.run();

	return 0;
}
