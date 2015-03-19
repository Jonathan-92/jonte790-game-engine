#include "Enemy.h"
#include <SDL.h>
#include <vector>
#include "Projectile.h"
#include "GameEngine.h"
#include <sstream>
#include <string>
#include "GameHandler.h"

using namespace std;
using namespace gameEngine;

Enemy::Enemy(int x, int y, int w, int h) : 
Sprite(x, y, w, h, "../images/enemy2.bmp", true), nextCp(1)
{
	health = pow(gh.getLevel(), 2) * 3;
	healthLabel = Label::getInstance(x + 50, y, 10, 10, to_string(health));
	ge().add(healthLabel);
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
	if (nextCp == 5) {
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
			ge().remove(*it);
			it = gh.projectiles.erase(it);
			health -= (*it)->damage;
		}
		else {
			++it;
		}
	}

	if (health < 1) {
		gh.increaseGold(value);
		delete this;
	}
}

void Enemy::setValue(int v) {
	value = v;
}

Enemy::~Enemy(void)
{
	ge().remove(healthLabel);
	delete healthLabel;
	ge().remove(this);
}