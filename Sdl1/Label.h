#ifndef LABEL_H
#define LABEL_H
#include "Sprite.h"
#include <string>

namespace gameEngine {

class Label :
	public Sprite
{
public:
	/* Here we define a name for a function pointer since it will be used a lot */
	typedef std::string (*FuncPtr)();
	static Label* getInstance(int x, int y, int w, int h, std::string text, 
		FuncPtr fp);
	static Label* getInstance(int x, int y, int w, int h, std::string text);
	void tick();
	void setText(std::string text);
	~Label();
protected:
	Label(int x, int y, int w, int h, std::string text, FuncPtr fp);
	Label(int x, int y, int w, int h, std::string text);
private:
	// add copy protection
	static const SDL_Color black;
	FuncPtr funcPtr;
	std::string(*FuncPtr)();
};

}

#endif