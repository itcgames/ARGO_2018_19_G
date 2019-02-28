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
	SDL_Surface* backgroundSurface = IMG_Load("ASSETS/MainmenuBackground.png");
	SDL_Surface* helpScene1 = IMG_Load("ASSETS/helpscreen1.png");
	SDL_Surface* helpScene2 = IMG_Load("ASSETS/helpscreen2.png");
	SDL_Surface* helpScene3 = IMG_Load("ASSETS/helpscreen3.png");
	SDL_Surface* helpScene4 = IMG_Load("ASSETS/helpscreen4.png");
	SDL_Surface* helpScene5 = IMG_Load("ASSETS/helpscreen5.png");
	SDL_Surface* helpScene6 = IMG_Load("ASSETS/helpscreen6.png");
	SDL_Surface* helpScene7 = IMG_Load("ASSETS/helpscreen7.png");

	m_MainMenuButtonTxt = SDL_CreateTextureFromSurface(renderer, mainMenuSurface);
	m_backgroundTxt = SDL_CreateTextureFromSurface(renderer, backgroundSurface);

	SDL_Texture* helpTxt = SDL_CreateTextureFromSurface(renderer, helpScene1);
	m_helpTextures.push_back(helpTxt);
	helpTxt = SDL_CreateTextureFromSurface(renderer, helpScene2);
	m_helpTextures.push_back(helpTxt);
	helpTxt = SDL_CreateTextureFromSurface(renderer, helpScene3);
	m_helpTextures.push_back(helpTxt);
	helpTxt = SDL_CreateTextureFromSurface(renderer, helpScene4);
	m_helpTextures.push_back(helpTxt);
	helpTxt = SDL_CreateTextureFromSurface(renderer, helpScene5);
	m_helpTextures.push_back(helpTxt);
	helpTxt = SDL_CreateTextureFromSurface(renderer, helpScene6);
	m_helpTextures.push_back(helpTxt);
	helpTxt = SDL_CreateTextureFromSurface(renderer, helpScene7);
	m_helpTextures.push_back(helpTxt);

	m_mainMenuButtonPos = new SDL_Rect();
	m_mainMenuButtonPos->x = 1600; m_mainMenuButtonPos->y = 680;
	m_mainMenuButtonPos->w = 200; m_mainMenuButtonPos->h = 200;

	m_backgroundPos = new SDL_Rect();
	m_backgroundPos->x = 0; m_backgroundPos->y = 0;
	m_backgroundPos->w = 1920; m_backgroundPos->h = 1080;

	helpTxtPos = new SDL_Rect();
	helpTxtPos->x = 0; helpTxtPos->y = 0;
	helpTxtPos->w = 1200; helpTxtPos->h = 800;

	m_index = 0;
}

void HelpScreen::update(GameState* gamestate, SDL_Renderer* renderer)
{
	while (SDL_PollEvent(&m_event))
	{
		if(m_event.type == SDL_MOUSEBUTTONDOWN)
		{ 
			switch (m_event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
			{
				SDL_GetMouseState(&mousePos->x, &mousePos->y);

				if (SDL_PointInRect(mousePos, m_mainMenuButtonPos))
				{
					initialise(renderer);
					*gamestate = GameState::MainMenu;
				}
				break;
			}
			}
		}
		else if (m_event.type == SDL_KEYDOWN)
		{
			switch (m_event.key.keysym.sym)
			{
			case SDLK_RIGHT:
			{
				m_index++;

				if (m_index > 6)
				{
					m_index = 0;
				}
				break;
			}

			case SDLK_LEFT:
			{
				m_index--;

				if (m_index < 0)
				{
					m_index = 6;
				}
				break;
			}
			}
		}
	}
}

void HelpScreen::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_backgroundTxt, NULL, m_backgroundPos);
	SDL_RenderCopy(renderer, m_helpTextures[m_index], NULL, helpTxtPos);
	SDL_RenderCopy(renderer, m_MainMenuButtonTxt, NULL, m_mainMenuButtonPos);
	
}