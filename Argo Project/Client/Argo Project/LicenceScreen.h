#pragma once
#include "SDL.h"
#include <iostream>

class LicenceScreen
{
public:
	LicenceScreen();
	~LicenceScreen();

	void update();
	void render(SDL_Renderer *renderer);

private:
	SDL_Surface *test;
	//
};

