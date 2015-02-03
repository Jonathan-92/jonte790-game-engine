#include "Label.h"
#include <string>
#include "Spawner.h"
#include "Sprite.h"
#include "GameEngine.h"
using namespace std;

namespace gameEngine {

	Label::Label(int x, int y, int w, int h, string text, FuncPtr fp) :
		Sprite(x, y, w, h, TTF_RenderText_Solid(ga.getFont(), text.c_str(), black)),
		funcPtr(fp)
	{
	}

	Label::Label(int x, int y, int w, int h, string text) :
		Label(x, y, w, h, text, nullptr)
	{
	}

	const SDL_Color Label::black = { 0, 0, 0 };

	void Label::tick() {
		if (funcPtr != nullptr)
			setText(funcPtr());
	}

	void Label::setText(std::string text)
	{
		setTexture(TTF_RenderText_Solid(ga.getFont(), text.c_str(), black));
	}

	Label* Label::getInstance(int x, int y, int w, int h, std::string text, FuncPtr fp){
		return new Label(x, y, w, h, text, fp);
	}

	Label* Label::getInstance(int x, int y, int w, int h, std::string text){
		return new Label(x, y, w, h, text);
	}

	Label::~Label(void)
	{
	}

}