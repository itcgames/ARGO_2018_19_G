#include "HelpScreen.h"



HelpScreen::HelpScreen(SDL_Renderer* renderer)
{
	initialise(renderer);
}


HelpScreen::~HelpScreen()
{
}
 

void HelpScreen::initialise(SDL_Renderer* renderer)
{
	mousePos = new SDL_Point();

	SDL_Surface* mainMenuSurface = IMG_Load("Resources/MainMenuBTN.png");
	m_MainMenuButtonTxt = SDL_CreateTextureFromSurface(renderer, mainMenuSurface);

	m_mainMenuButtonPos = new SDL_Rect();

	m_mainMenuButtonPos->x = 1200; m_mainMenuButtonPos->y = 800;
	m_mainMenuButtonPos->w = 200; m_mainMenuButtonPos->h = 200;
}

void HelpScreen::update(GameState* gamestate)
{
	while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			SDL_GetMouseState(&mousePos->x, &mousePos->y);

			if (SDL_PointInRect(mousePos, m_mainMenuButtonPos))
			{
				*gamestate = GameState::MainMenu;
			}
		}
	}
}

void HelpScreen::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_MainMenuButtonTxt, NULL, m_mainMenuButtonPos);
}