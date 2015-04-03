#ifndef BASICTOWER_H
#define BASICTOWER_H

#include "Tower.h"

class BasicTower :
	public Tower
{
public:
	static const int goldCost;
	BasicTower(int x, int y, int w, int h);
	~BasicTower();
};

#endif