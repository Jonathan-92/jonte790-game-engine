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


int Enemy::value;
const int Enemy::SPEED = 2;
const int Enemy::DAMAGE = 1;
const int Enemy::FINAL_CHECKPOINT = 4;

Enemy::Enemy(int x, int y, int w, int h) : 
Sprite(x, y, w, h, "../images/enemy2.bmp", true), nextCp(1)
{
	health = pow(gh.getLevel(), 2) * 3;
	healthLabel = Label::getInstance(x + 75, y, 20, 20, to_string(health));
	ge().add(healthLabel);
}

Enemy::~Enemy(void)
{
	ge().remove(healthLabel);
	delete healthLabel;
	ge().remove(this);
}

/* The difference between this instance's position and the next checkpoint's
position is calculated and then the x and y values are adjusted in accordance
to move the instance closer to the next checkpoint. When there is no difference
between the position and the next checkpoint, that means the checkpoint has been 
reached, and the nextCp variable can be incremented. */
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
	if (nextCp == FINAL_CHECKPOINT + 1) { // Has the last checkpoint been reached?
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

/* Checks whether any Projectile has hit this instance. If so, the projectile
is removed and the health of this instance is decreased. If health has reached
0, this instance is deleted and the player's gold is increased. */
void Enemy::checkIfHit() {
	Projectile* projectile = gh.overlaps(this);

	if (projectile != nullptr) {
		ge().remove(projectile);
		gh.removeProjectile(projectile);
		health -= (projectile)->getDamage();
	}

	if (health < 1) { // The Enemy has been eliminated
		gh.increaseGold(value);
		delete this;
	}
}

void Enemy::setValue(int v) {
	value = v;
}

