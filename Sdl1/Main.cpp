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

using namespace gameEngine;
using namespace std;

Spawner* spawner = Spawner::getInstance();
Builder* builder = Builder::getInstance();

void quit() {
	exit(0);
}

void start() {
	spawner->start();
}

void buildBasicTower() {
	builder->building_tower &= 0U;
	builder->building_tower |= BUILDING_BASIC;
}

void buildAdvancedTower() {
	builder->building_tower &= 0U;
	builder->building_tower |= BUILDING_ADVANCED;
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
	return updateLabel(gh.gold, "Gold: ");
}

string updateLevel() {
	return updateLabel(gh.getLevel(), "Level: ");
}

void addLabels()
{
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
}

void addButtons()
{
	G_Button* basicTowerButton = new G_Button(105, 730, 50, 50, "../images/basic_tower.bmp", buildBasicTower);
	ga.add(basicTowerButton);

	G_Button* advancedTowerButton = new G_Button(375, 730, 50, 50, "../images/advanced_tower.bmp", buildAdvancedTower);
	ga.add(advancedTowerButton);

	G_Button* startButton = new G_Button(5, 705, 75, 25, "../images/startButton.bmp", start);
	ga.add(startButton);

	G_Button* quitButton = new G_Button(5, 755, 75, 25, "../images/quitButton.bmp", quit);
	ga.add(quitButton);
}

int main(int argc, char** argv) {
	ga.setVideoMode(900, 800);
	ga.setBackground("../images/map.bmp");
	ga.setFps(100);

	ga.add(spawner);
	ga.add(builder);
	addLabels();
	addButtons();

	ga.run();

	return 0;
}

