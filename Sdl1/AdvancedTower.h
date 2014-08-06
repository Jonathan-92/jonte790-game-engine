#ifndef ADVANCEDTOWER_H
#define ADVANCEDTOWER_H
#include "Tower.h"

class AdvancedTower :
	public Tower
{
public:
	AdvancedTower(int x, int y, int w, int h);
	~AdvancedTower();
	void mouseDown(int x, int y);
	void tick();
};

#endif