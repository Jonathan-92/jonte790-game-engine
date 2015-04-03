#ifndef G_BUTTON_H
#define G_BUTTON_H

#include "Sprite.h"
#include <SDL.h>

namespace gameEngine {

	/* A button which can have different behaviours depending on what function
	is passed to the constructor */
	class G_Button : public gameEngine::Sprite {
	public:
		/* A name for a function pointer is defined for easier reference. */
		typedef void(*FuncPtr)();
		
		/* 
		param "x" = the x coordinate
		param "y" = the y coordinate
		param "w" = the width
		param "h" = the height
		param "imgPath" = the path to the image which the button will have
		param "fp" = a function pointer to the function that the button will
		call when it is clicked
		*/
		G_Button(int x, int y, int w, int h, std::string imgPath, FuncPtr fp);
		
		~G_Button(void);
		void tick();
		void mouseDown(int x, int y);
		
		/* Disables this button */
		void disable();
	private:
		FuncPtr funcPtr;
		bool enabled;
	};

}

#endif