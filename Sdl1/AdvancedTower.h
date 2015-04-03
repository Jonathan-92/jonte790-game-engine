#ifndef ADVANCEDTOWER_H
#define ADVANCEDTOWER_H
#include "Tower.h"

class AdvancedTower :
	public Tower
{
public:
	static const int goldCost;
	AdvancedTower(int x, int y, int w, int h);
	~AdvancedTower();
};

#endif