#ifndef ADVANCEDTOWER_H
#define ADVANCEDTOWER_H
#include "Tower.h"

class AdvancedTower :
	public Tower
{
public:
	AdvancedTower(int x, int y, int w, int h);
	~AdvancedTower();
	static const int goldCost;
};

#endif