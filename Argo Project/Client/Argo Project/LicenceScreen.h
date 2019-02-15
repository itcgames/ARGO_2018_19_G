#pragma once
#include "SDL.h"
#include <iostream>
#include <SDL_image.h>
class LicenceScreen
{
public:
	LicenceScreen(SDL_Renderer* renderer);
	~LicenceScreen();

	void initialise(SDL_Renderer* renderer);
	void update();
	void render(SDL_Renderer *renderer);

private:
	SDL_Texture* m_texture;
	SDL_Rect* m_position;
	//
};

