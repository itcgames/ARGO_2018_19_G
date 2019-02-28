#include "CreditsScreen.h"

CreditsScreen::CreditsScreen(SDL_Renderer* renderer)
{
	initialise(renderer);
}

CreditsScreen::~CreditsScreen()
{
}

void CreditsScreen::update(GameState* gamestate)
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

void CreditsScreen::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_backgroundTxt, NULL, m_backgroundPos);
	SDL_RenderCopy(renderer, m_MainMenuButtonTxt, NULL, m_mainMenuButtonPos);
}

void CreditsScreen::initialise(SDL_Renderer* renderer)
{
	mousePos = new SDL_Point();

	SDL_Surface* mainMenuSurface = IMG_Load("Resources/MainMenuBTN.png");
	SDL_Surface* backgroundSurface = IMG_Load("ASSETS/MainmenuBackground.png");

	m_MainMenuButtonTxt = SDL_CreateTextureFromSurface(renderer, mainMenuSurface);
	m_backgroundTxt = SDL_CreateTextureFromSurface(renderer, backgroundSurface);

	m_mainMenuButtonPos = new SDL_Rect();
	m_mainMenuButtonPos->x = 1600; m_mainMenuButtonPos->y = 680;
	m_mainMenuButtonPos->w = 200; m_mainMenuButtonPos->h = 200;

	m_backgroundPos = new SDL_Rect();
	m_backgroundPos->x = 0; m_backgroundPos->y = 0;
	m_backgroundPos->w = 1920; m_backgroundPos->h = 1080;
}

