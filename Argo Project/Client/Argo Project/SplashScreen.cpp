#include "SplashScreen.h"



SplashScreen::SplashScreen(SDL_Renderer* renderer)
{
	initialise(renderer);
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::initialise(SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load("ASSETS/splashScreen2.png");
	m_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	m_position = new SDL_Rect();

	m_position->x = 0;
	m_position->y = 0;
	m_position->w = 1920;
	m_position->h = 1080;
}

void SplashScreen::update(GameState* gameState)
{
	while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type)
		{
		case SDL_KEYDOWN:
			*gameState = GameState::MainMenu;
		}
	}

	std::cout << "updating splash" << std::endl;
}

void SplashScreen::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_texture, NULL, m_position);
}
