#include <SDL.h>
#include "GameEngine.h"
#include "Enemy.h"
#include "G_Button.h"
#include "Spawner.h"
#include <Windows.h>
#include "Label.h"
#include <sstream>
#include "GameHandler.h"
#include "Builder.h"
#include <iostream>
#include "BasicTower.h"
#include "AdvancedTower.h"

using namespace gameEngine;
using namespace std;

Builder* builder;

void quit() {
	exit(0);
}

void buildBasicTower() {
	builder->enableBuilding(BasicTower::goldCost, BUILDING_BASIC);
}

void buildAdvancedTower() {
	builder->enableBuilding(AdvancedTower::goldCost, BUILDING_ADVANCED);
}

string updateLabel(int value, string label) {
	ostringstream os;
	os << label << value;
	return os.str();
}

string updateLives() {
	return updateLabel(gh.getLives(), "Lives: ");
}

string updateGold() {
	return updateLabel(gh.getGold(), "Gold: ");
}

string updateLevel() {
	return updateLabel(gh.getLevel(), "Level: ");
}

void addLabels()
{
	Label* lives = Label::getInstance(800, 10, 50, 15, "Lives: ", updateLives);
	ge().add(lives);

	Label* points = Label::getInstance(10, 10, 50, 15, "Level: ", updateLevel);
	ge().add(points);

	Label* gold = Label::getInstance(10, 35, 50, 15, "Gold: ", updateGold);
	ge().add(gold);

	Label* basicTowerLabel = Label::getInstance(105, 705, 200, 25, "Build  Basic Tower (5 gold): ");
	ge().add(basicTowerLabel);

	Label* advancedTowerLabel = Label::getInstance(375, 705, 230, 25, "Build  Advanced Tower (10 gold): ");
	ge().add(advancedTowerLabel);
}

void addButtons()
{
	G_Button* basicTowerButton = G_Button::getInstance(105, 730, 50, 50, "../images/basic_tower.bmp", buildBasicTower);
	ge().add(basicTowerButton);

	G_Button* advancedTowerButton = G_Button::getInstance(375, 730, 50, 50, "../images/advanced_tower.bmp", buildAdvancedTower);
	ge().add(advancedTowerButton);

	G_Button* quitButton = G_Button::getInstance(5, 755, 90, 40, "../images/quitButton.bmp", quit);
	ge().add(quitButton);
}

int main(int argc, char** argv) {
	try {
		builder = Builder::getInstance();

		ge().setVideoMode(900, 800);
		ge().setBackground("../images/map.bmp");
		ge().setFps(100);

		ge().add(builder);
		addLabels();
		addButtons();

		ge().run();
	}
	catch (runtime_error& rte) {
		cerr << rte.what() << endl;
	}

	return 0;
}

