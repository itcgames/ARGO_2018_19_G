#pragma once
#include <SDL.h>
class OptionsScreen
{
public:
	OptionsScreen();
	~OptionsScreen();

	void update();
	void render(SDL_Renderer *renderer);
};

