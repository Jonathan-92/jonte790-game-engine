#ifndef TOWER_H
#define TOWER_H

#include "Sprite.h"
#include "Projectile.h"

//template <typename T>
class Tower : public gameEngine::Sprite {
public:
	~Tower(void);
	int getGoldCost();
protected:
	Tower(int x, int y, int w, int h, std::string imgPath);
	int goldCost;
	int damage;
	int speed;
private:
	Tower(const Tower&);
	const Tower& operator=(const Tower&);
};


#endif