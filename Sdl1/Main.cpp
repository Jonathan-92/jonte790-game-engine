#include <SDL.h>
#include "GameEngine.h"
#include "Globals.h"
#include "Enemy.h"
#include "G_Button.h"
#include "Spawner.h"
#include <Windows.h>
#include "Label.h"
#include <sstream>

using namespace gameEngine;
using namespace std;

void quit() {
	exit(0);
}

void start() {
	Spawner::start();
}

void buildBasicTower() {
	Spawner::building_tower &= 0U;
	Spawner::building_tower |= BUILDING_BASIC;
}

void buildAdvancedTower() {
	Spawner::building_tower &= 0U;
	Spawner::building_tower |= BUILDING_ADVANCED;
}

string updateLabel(int value, string label) {
	ostringstream os;
	os << label << value;
	return os.str();
}

string updateLives() {
	return updateLabel(Spawner::lives, "Lives: ");
}

string updateGold() {
	return updateLabel(Spawner::gold, "Gold: ");
}

string updateLevel() {
	return updateLabel(Spawner::level, "Level: ");
}

int main(int argc, char** argv) {
	ga.setVideoMode(900, 800);
	ga.setBackground("../images/map.bmp");
	ga.setFps(100);
	ga.add(new Spawner());

	Label* lives = Label::getInstance(800, 10, 50, 10, "Lives: ", updateLives);
	ga.add(lives);

	Label* points = Label::getInstance(10, 10, 50, 10, "Level: ", updateLevel);
	ga.add(points);

	Label* gold = Label::getInstance(10, 35, 50, 10, "Gold: ", updateGold);
	ga.add(gold);

	Label* basicTowerLabel = Label::getInstance(105, 705, 50, 10, "Build  Basic Tower (5 gold): ");
	ga.add(basicTowerLabel);

	Label* advancedTowerLabel = Label::getInstance(375, 705, 50, 10, "Build  Advanced Tower (10 gold): ");
	ga.add(advancedTowerLabel);

	G_Button* basicTowerButton = new G_Button(105, 730, 50, 50, "../images/basic_tower.bmp", buildBasicTower);
	ga.add(basicTowerButton);

	G_Button* advancedTowerButton = new G_Button(375, 730, 50, 50, "../images/advanced_tower.bmp", buildAdvancedTower);
	ga.add(advancedTowerButton);

	G_Button* startButton = new G_Button(5, 705, 75, 25, "../images/startButton.bmp", start);
	ga.add(startButton);

	G_Button* quitButton = new G_Button(5, 755, 75, 25, "../images/quitButton.bmp", quit);
	ga.add(quitButton);

	ga.run();

	return 0;
}
