#pragma once

#include <SDL.h>
class CreditsScreen
{
public:
	CreditsScreen();
	~CreditsScreen();

	void update();
	void render(SDL_Renderer *renderer);
};

