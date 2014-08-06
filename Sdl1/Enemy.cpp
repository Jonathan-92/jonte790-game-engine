#include "Enemy.h"
#include "Globals.h"
#include <SDL.h>
#include <vector>
#include "Projectile.h"
#include "Spawner.h"
#include "GameEngine.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace gameEngine;

Enemy::Enemy(int x, int y, int w, int h) : Sprite(x, y, w, h), health(health)
{
	image = SDL_DisplayFormat(SDL_LoadBMP("../images/enemy2.bmp"));	// fixa PNG
	Uint32 transp = *(Uint32*)image->pixels;
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
	healthLabel = Label::getInstance(x + 70, y, 40, 10, "5");
	ga.add(healthLabel);
	health = pow(Spawner::level, 2) * 3;
	speed = 2;
}

void Enemy::draw() {
	SDL_BlitSurface(image, NULL, sys.screen, &rect);
}

int Enemy::value;

void Enemy::tick() {
	rect.y += speed;
	healthLabel->rect.y += speed;

	ostringstream os;
	os << health;
	healthLabel->setText(os.str());
	
	if (rect.y > 800) {
		Spawner::lives--;
		delete this;
		return;
	}

	checkIfHit();

	if (health < 1) {
		Spawner::gold += value;
		delete this;
	}
}

void Enemy::checkIfHit() {
	std::vector<Projectile*>::iterator it = Spawner::projectiles.begin();

	while (it != Spawner::projectiles.end()) {
		if ((*it)->rect.overlaps(rect)) {
			ga.remove(*it);
			it = Spawner::projectiles.erase(it);
			health -= (*it)->getDamage();
		} else {
			++it;
		}
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