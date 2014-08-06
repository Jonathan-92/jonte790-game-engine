#include "Label.h"
#include <string>
#include "Globals.h"
#include "Spawner.h"
#include "Sprite.h"
using namespace std;

namespace gameEngine {

Label::Label(int x, int y, int w, int h, string text, FuncPtr fp) :
		Sprite(x,y,w,h), text(text), funcPtr(fp)
	{
		SDL_Color black = {0,0,0};
		image = TTF_RenderText_Solid(sys.font, text.c_str(), black);
	}

Label::Label(int x, int y, int w, int h, string text) :
		Sprite(x,y,w,h), text(text), funcPtr(NULL)
	{
		SDL_Color black = {0,0,0};
		image = TTF_RenderText_Solid(sys.font, text.c_str(), black);
	}

void Label::draw() {
	SDL_BlitSurface(image,NULL,sys.screen, &rect);
}

void Label::tick() {
	if (funcPtr != NULL)
		setText(funcPtr());
}

void Label::setText(std::string newText)
	{
		text = newText;
		SDL_Color svart = {0,0,0};
		SDL_FreeSurface(image);
		image = TTF_RenderText_Solid(sys.font, text.c_str(), svart);
		draw();
	}

Label* Label::getInstance(int x, int y, int w, int h, std::string text, FuncPtr fp){
	return new Label(x,y,w,h,text, fp);
}

Label* Label::getInstance(int x, int y, int w, int h, std::string text){
	return new Label(x,y,w,h,text);
}

Label::~Label(void)
{
}

}