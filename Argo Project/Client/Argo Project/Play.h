#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "MenuManager.h"

class PlayScreen
{
public:
	PlayScreen(SDL_Renderer* renderer);
	~PlayScreen();

	void initialise(SDL_Renderer* renderer);
	void update(GameState *gameState);
	void render(SDL_Renderer *renderer);

private:
	SDL_Event m_event;
	SDL_Texture* m_texture;
	SDL_Rect* m_position;
};