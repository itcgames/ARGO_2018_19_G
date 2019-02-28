#include "MainMenuScene.h"

MainMenuScreen::MainMenuScreen(SDL_Renderer* renderer)
{
	initialise(renderer);
}

MainMenuScreen::~MainMenuScreen()
{
}

void MainMenuScreen::initialise(SDL_Renderer* renderer)
{
	initButtons(renderer);

	mouse = new SDL_Point();
}

void MainMenuScreen::update(GameState* gameState)
{
	while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			SDL_GetMouseState(&mouse->x, &mouse->y);

			if (SDL_PointInRect(mouse, m_playPos))
			{
				*gameState = GameState::Play;
			}

			if (SDL_PointInRect(mouse, m_creditsPos))
			{
				*gameState = GameState::Credits;
			}

			if (SDL_PointInRect(mouse, m_quitPos))
			{
				SDL_Quit();
			}

			if (SDL_PointInRect(mouse, m_helpPos))
			{
				*gameState = GameState::Help;
			}
		}
	}
}

void MainMenuScreen::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_backgroundTxt, NULL, m_backgroundPos);

	SDL_RenderCopy(renderer, m_playTxt, NULL, m_playPos);
	SDL_RenderCopy(renderer, m_helpTxt, NULL, m_helpPos);
	SDL_RenderCopy(renderer, m_quitTxt, NULL, m_quitPos);

	SDL_RenderCopy(renderer, m_creditsTxt, NULL, m_creditsPos);
}

void MainMenuScreen::initButtons(SDL_Renderer* renderer)
{
	SDL_Surface* playSurface = IMG_Load("Resources/PlayBTN.png");
	SDL_Surface* creditsSurface = IMG_Load("ASSETS/Credit.png");
	SDL_Surface* helpSurface = IMG_Load("Resources/HelpBTN.png");
	SDL_Surface* quitSurface = IMG_Load("Resources/QuitBTN.png");
	SDL_Surface* backgroundSurface = IMG_Load("ASSETS/MainmenuBackground.png");

	m_playTxt = SDL_CreateTextureFromSurface(renderer, playSurface);
	m_creditsTxt = SDL_CreateTextureFromSurface(renderer, creditsSurface);
	m_helpTxt = SDL_CreateTextureFromSurface(renderer, helpSurface);
	m_quitTxt = SDL_CreateTextureFromSurface(renderer, quitSurface);
	m_backgroundTxt = SDL_CreateTextureFromSurface(renderer, backgroundSurface);

	m_creditsPos = new SDL_Rect();
	m_playPos = new SDL_Rect();
	m_helpPos = new SDL_Rect();
	m_quitPos = new SDL_Rect();

	m_playPos->x = 860; m_playPos->y = 50;
	m_playPos->w = 200; m_playPos->h = 200;

	m_helpPos->x = 860; m_helpPos->y = 250;
	m_helpPos->w = 200; m_helpPos->h = 200;

	m_creditsPos->x = 860; m_creditsPos->y = 450;
	m_creditsPos->w = 200; m_creditsPos->h = 200;

	m_quitPos->x = 860; m_quitPos->y = 650;
	m_quitPos->w = 200; m_quitPos->h = 200;

	m_backgroundPos = new SDL_Rect();
	m_backgroundPos->x = 0; m_backgroundPos->y = 0;
	m_backgroundPos->w = 1920; m_backgroundPos->h = 1080;
}