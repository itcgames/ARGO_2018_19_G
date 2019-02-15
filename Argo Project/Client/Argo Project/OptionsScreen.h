#pragma once
#include <SDL.h>
class OptionsScreen
{
public:
	OptionsScreen(SDL_Renderer* renderer);
	~OptionsScreen();

	void initialise(SDL_Renderer* renderer);
	void update();
	void render(SDL_Renderer *renderer);
};

