#pragma once

#include <SDL.h>
class HelpScreen
{
public:
	HelpScreen();
	~HelpScreen();

	void update();
	void render(SDL_Renderer *renderer);
};

