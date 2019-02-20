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

			if (SDL_PointInRect(mouse, m_optionsPos))
			{
				*gameState = GameState::Options;
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
	SDL_RenderCopy(renderer, m_playTxt, NULL, m_playPos);
	SDL_RenderCopy(renderer, m_helpTxt, NULL, m_helpPos);
	SDL_RenderCopy(renderer, m_optionsTxt, NULL, m_optionsPos);
	SDL_RenderCopy(renderer, m_quitTxt, NULL, m_quitPos);
}


void MainMenuScreen::initButtons(SDL_Renderer* renderer)
{
	SDL_Surface* playSurface = IMG_Load("Resources/PlayBTN.png");
	SDL_Surface* optionsSurface = IMG_Load("Resources/OptionsBTN.png");
	SDL_Surface* helpSurface = IMG_Load("Resources/HelpBTN.png");
	SDL_Surface* quitSurface = IMG_Load("Resources/QuitBTN.png");

	m_playTxt = SDL_CreateTextureFromSurface(renderer, playSurface);
	m_optionsTxt = SDL_CreateTextureFromSurface(renderer, optionsSurface);
	m_helpTxt = SDL_CreateTextureFromSurface(renderer, helpSurface);
	m_quitTxt = SDL_CreateTextureFromSurface(renderer, quitSurface);

	m_optionsPos = new SDL_Rect();
	m_playPos = new SDL_Rect();
	m_helpPos = new SDL_Rect();
	m_quitPos = new SDL_Rect();

	m_playPos->x = 860; m_playPos->y = 100;
	m_playPos->w = 200; m_playPos->h = 200;

	m_helpPos->x = 860; m_helpPos->y = 300;
	m_helpPos->w = 200; m_helpPos->h = 200;

	m_optionsPos->x = 860; m_optionsPos->y = 500;
	m_optionsPos->w = 200; m_optionsPos->h = 200;

	m_quitPos->x = 860; m_quitPos->y = 700;
	m_quitPos->w = 200; m_quitPos->h = 200;
}



/*
checkCollisionBetween(clickPos, x,y,width,height)
{
var collides = false;
if ((clickPos[0] < x + width) &&
(clickPos[0] > x) &&
(clickPos[1] < y + height) &&
(clickPos[1] > y)){

collides = true;
}
return collides;
}

*/