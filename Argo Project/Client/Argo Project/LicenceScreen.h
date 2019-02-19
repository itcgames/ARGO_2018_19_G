#pragma once

#include "SDL.h"
#include <iostream>
#include <SDL_image.h>
#include "MenuManager.h"

class LicenceScreen
{
public:
	LicenceScreen(SDL_Renderer* renderer);
	~LicenceScreen();

	void initialise(SDL_Renderer* renderer);
	void update(GameState *gameState);
	void render(SDL_Renderer *renderer);
private:
	SDL_Event m_event;
	SDL_Texture* m_texture;
	SDL_Rect* m_position;
	//
};