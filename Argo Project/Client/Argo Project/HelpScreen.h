#pragma once

#include <SDL.h>
#include <vector>
#include <SDL_image.h>
#include "MenuManager.h"
class HelpScreen
{
public:
	HelpScreen(SDL_Renderer* renderer);
	~HelpScreen();

	void initialise(SDL_Renderer* renderer);
	void update(GameState* gameState, SDL_Renderer* renderer);
	void render(SDL_Renderer *renderer);

private:
	SDL_Point * mousePos;
	SDL_Event m_event;
	SDL_Texture* m_MainMenuButtonTxt;

	std::vector<SDL_Texture*> m_helpTextures;

	SDL_Texture* m_backgroundTxt;
	SDL_Rect* m_mainMenuButtonPos;
	SDL_Rect* m_backgroundPos;
	SDL_Rect* helpTxtPos;

	int m_index;
};

