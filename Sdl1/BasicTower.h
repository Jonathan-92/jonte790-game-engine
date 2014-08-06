#ifndef BASICTOWER_H
#define BASICTOWER_H

#include "Tower.h"

class BasicTower :
	public Tower
{
public:
	BasicTower(int x, int y, int w, int h);
	~BasicTower();
	void mouseDown(int x, int y);
	void tick();
};

#endif