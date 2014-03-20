#include "Enemy.h"
#include "Globals.h"
#include <SDL.h>
#include <vector>
#include "Projectile.h"
#include "Spawner.h"
#include "GameEngine.h"

using namespace gameEngine;

int Enemy::health = 10;

Enemy::Enemy(int x, int y, int w, int h):Sprite(x,y,w,h)
{
	image = SDL_DisplayFormat(SDL_LoadBMP("C:/users/Jonathan/Pictures/Prog3 spel/enemy2.bmp"));	// fixa PNG
	Uint32 transp = *(Uint32*)image->pixels;
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
}

void Enemy::draw() {
	SDL_BlitSurface(image, NULL, sys.screen, &rect);
}

void Enemy::tick() {
	rect.y++;
	checkIfHit();
}

void Enemy::checkIfHit() {
	for (std::vector<Projectile*>::iterator it = Spawner::projectiles.begin(); it != 
					Spawner::projectiles.end(); it++) {
			if ((*it)->rect.overlaps(rect)) {
				ga.remove(*it);
			}
		}
}

void Enemy::upHealth(int h) {
	health += h;
}

Enemy::~Enemy(void)
{

}