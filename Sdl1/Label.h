#ifndef LABEL_H
#define LABEL_H
#include "Sprite.h"
#include <string>

namespace gameEngine {

class Label :
	public Sprite
{
public:
	typedef std::string (*FuncPtr)();
	static Label* getInstance(int x, int y, int w, int h, std::string text, FuncPtr fp);
	static Label* getInstance(int x, int y, int w, int h, std::string text);
	void draw();
	void tick();
	void setText(std::string);
	~Label(void);
private:
	FuncPtr funcPtr;
	Label(int x, int y, int w, int h, std::string text, FuncPtr fp);
	Label(int x, int y, int w, int h, std::string text);
	std::string text;
	SDL_Surface* image;
};

}

#endif