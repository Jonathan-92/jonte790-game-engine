#ifndef TOWER_H
#define TOWER_H

#include "Sprite.h"
#include <string>

class Tower : public gameEngine::Sprite {
public:
	~Tower(void);
	void mousePressed(int x, int y);
	const static int goldCost; //?
	std::string projImage;
	int damage;
	int speed;
protected:
	Tower(int x, int y, int w, int h, std::string imgPath, std::string projImage);
private:
	SDL_TimerID myTimerID;
	Uint32 startTimer;
	Tower(const Tower&);
	const Tower& operator=(const Tower&);
};


#endif