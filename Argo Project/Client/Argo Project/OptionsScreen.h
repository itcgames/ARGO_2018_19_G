#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "MenuManager.h"
class OptionsScreen
{
public:
	OptionsScreen(SDL_Renderer* renderer);
	~OptionsScreen();

	void initialise(SDL_Renderer* renderer);
	void update(GameState* gameState);
	void render(SDL_Renderer *renderer);

private:
	SDL_Point* mousePos;
	SDL_Event m_event;
	SDL_Texture* m_MainMenuButtonTxt;
	SDL_Rect* m_mainMenuButtonPos;
};

