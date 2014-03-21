#include "Enemy.h"
#include "Globals.h"
#include <SDL.h>
#include <vector>
#include "Projectile.h"
#include "Spawner.h"
#include "GameEngine.h"
#include <iostream>

using namespace gameEngine;


Enemy::Enemy(int x, int y, int w, int h):Sprite(x,y,w,h)
{
	image = SDL_DisplayFormat(SDL_LoadBMP("../images/enemy2.bmp"));	// fixa PNG
	Uint32 transp = *(Uint32*)image->pixels;
	SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
	health = 10;
}

void Enemy::draw() {
	SDL_BlitSurface(image, NULL, sys.screen, &rect);
}

void Enemy::tick() {
	rect.y++;
	checkIfHit();

	if (rect.y < 0) {
		delete this;
	}
}

void Enemy::checkIfHit() {
	for (std::vector<Projectile*>::iterator it = Spawner::projectiles.begin(); it != 
					Spawner::projectiles.end(); it++) {
			if ((*it)->rect.overlaps(rect)) {
				ga.remove(*it);

				if(--health == 0) {
					ga.remove(this);
					std::cout << "jag dör nu";
					return;
				}
			}
		}
}

Enemy::~Enemy(void)
{

}