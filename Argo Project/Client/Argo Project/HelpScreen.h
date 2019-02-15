#pragma once

#include <SDL.h>
class HelpScreen
{
public:
	HelpScreen(SDL_Renderer* renderer);
	~HelpScreen();

	void initialise(SDL_Renderer* renderer);
	void update();
	void render(SDL_Renderer *renderer);
};

