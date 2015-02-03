#include "Enemy.h"

#include <SDL.h>
#include <vector>
#include "Projectile.h"
#include "Spawner.h"
#include "GameEngine.h"
#include <iostream>
#include <sstream>
#include <string>
#include "GameHandler.h"

using namespace std;
using namespace gameEngine;

Enemy::Enemy(int x, int y, int w, int h) : 
Sprite(x, y, w, h, "../images/enemy2.bmp"), nextCp(1)
{
	healthLabel = Label::getInstance(x + 150, y, 40, 10, "5");
	ga.add(healthLabel);
	health = pow(gh.getLevel(), 2) * 3;
}

int Enemy::value;

void Enemy::move() {
	int xDiff = rect.centeredX() - gh.checkpoints[nextCp].x;
	int yDiff = rect.centeredY() - gh.checkpoints[nextCp].y;

	if (xDiff < 0) {
		rect.x += SPEED;
		healthLabel->rect.x += SPEED;
	}
	else if (xDiff > 0) {
		rect.x -= SPEED;
		healthLabel->rect.x -= SPEED;
	}

	if (yDiff < 0) {
		rect.y += SPEED;
		healthLabel->rect.y += SPEED;
	}
	else if (yDiff > 0) {
		rect.y -= SPEED;
		healthLabel->rect.y -= SPEED;
	}

	if (xDiff == 0 && yDiff == 0) {
		++nextCp;
	}
}

void Enemy::tick() {
	if (nextCp == FINISHED) {
		gh.decreaseLives(DAMAGE);
		delete this;
		return;
	}

	move();

	ostringstream os;
	os << health;
	healthLabel->setText(os.str());

	checkIfHit();
}

void Enemy::checkIfHit() {
	std::vector<Projectile*>::iterator it = gh.projectiles.begin();

	while (it != gh.projectiles.end()) {
		if ((*it)->rect.overlaps(rect)) {
			ga.remove(*it);
			it = gh.projectiles.erase(it);
			health -= (*it)->getDamage();
		}
		else {
			++it;
		}
	}

	if (health < 1) {
		gh.gold += value;
		delete this;
	}
}

void Enemy::setValue(int v) {
	value = v;
}

Enemy::~Enemy(void)
{
	ga.remove(healthLabel);
	delete healthLabel;
	ga.remove(this);
}