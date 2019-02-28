#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "MenuManager.h"
class CreditsScreen
{
public:
	CreditsScreen(SDL_Renderer* renderer);
	~CreditsScreen();

	void initialise(SDL_Renderer* renderer);
	void update(GameState* gameState);
	void render(SDL_Renderer *renderer);

private:
	SDL_Point * mousePos;
	SDL_Event m_event;
	SDL_Texture* m_MainMenuButtonTxt;
	SDL_Texture* m_backgroundTxt;
	SDL_Texture* m_creditTxt;
	SDL_Rect* m_mainMenuButtonPos;
	SDL_Rect* m_backgroundPos;
	SDL_Rect* m_creditPos;
};

