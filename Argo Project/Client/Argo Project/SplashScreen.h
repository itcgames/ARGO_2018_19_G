#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "MenuManager.h"

#ifndef SPLASH
#define SPLASH

class SplashScreen
{
public:
	SplashScreen(SDL_Renderer* renderer);
	~SplashScreen();

	void initialise(SDL_Renderer* renderer);
	void update(GameState *gameState);
	void render(SDL_Renderer *renderer);

private:
	SDL_Event m_event;
	SDL_Texture* m_texture;
	SDL_Rect* m_position;
};


#endif // !SPLASH