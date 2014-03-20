#ifndef G_BUTTON_H
#define G_BUTTON_H
#include "Sprite.h"
#include <SDL.h>

class G_Button : public gameEngine::Sprite {
public:
	typedef void (*FuncPtr)();
	G_Button(int x, int y, int w, int h, const char* imgPath, FuncPtr fp);
	~G_Button(void);
	void draw();
	void tick();
	void mouseDown(int x, int y);
private:
	FuncPtr funcPtr;
	SDL_Surface* image;
};

#endif