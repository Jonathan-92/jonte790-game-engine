#ifndef TOWER_H
#define TOWER_H
#include "Sprite.h"

class Tower : public gameEngine::Sprite {
public:
	~Tower(void);
	virtual void tick();
	virtual void draw();
	virtual void mouseDown(int x, int y);
	static int getGoldCost();
protected:
	Tower(int x, int y, int w, int h);
	static int goldCost;
private:
	Tower(const Tower&);
	const Tower& operator=(const Tower&);
};


#endif