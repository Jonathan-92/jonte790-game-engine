#ifndef TOWER_H
#define TOWER_H

#include "Sprite.h"
#include <string>

class Tower : public gameEngine::Sprite {
public:
	const static int goldCost;
	~Tower(void);
	void mousePressed(int x, int y);
	int getDamage() const;
	int getSpeed() const;
	std::string projImage;
protected:
	Tower(int x, int y, int w, int h, std::string imgPath, std::string projImage);
	int damage;
	int speed;
private:
	Tower(const Tower&);
	const Tower& operator=(const Tower&);
	Uint32 startTimer;
};


#endif