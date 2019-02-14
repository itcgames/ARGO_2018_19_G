//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:21 4 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "Game.h"

/// <summary>
/// 
/// </summary>
Game::Game()
{

}

/// <summary>
/// 
/// </summary>
Game::~Game()
{

}

/// <summary>
/// 
/// </summary>
/// <param name="title"></param>
/// <param name="xpos"></param>
/// <param name="ypos"></param>
/// <param name="width"></param>
/// <param name="height"></param>
void Game::init(const char* title, int xpos, int ypos, int width, int height)
{
	int flags = 0;

	//
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		m_isRunning = true;
		m_currentGamestate = GameState::Licence;
	}

	//
	else
	{
		m_isRunning = false;
	}
}

/// <summary>
/// 
/// </summary>
void Game::handleEvents()
{
	SDL_Event event_;
	SDL_PollEvent(&event_);
	switch (event_.type)
	{
	case SDL_QUIT:
		m_isRunning = false;
		break;

	default:
		break;
	}
}

void Game::run()
{
	while (m_isRunning)
	{
		update();
		render();
	}
}

//
void Game::update() 
{
	switch (m_currentGamestate)
	{
		case GameState::Licence:
		{
			m_licenceScreen.update();
			break;
		}
		case GameState::Splash:
		{
			m_splashScreen.update();
			break;
		}
		case GameState::MainMenu:
		{
			m_mainMenuScreen.update();
			break;
		}
		case GameState::Options:
		{
			m_optionsScreen.update();
			break;
		}
		case GameState::Help:
		{
			m_helpScreen.update();
			break;
		}
	}
}

/// <summary>
/// 
/// </summary>
void Game::render() 
{
	SDL_RenderClear(renderer);

	switch (m_currentGamestate)
	{
		case GameState::Licence:
		{
			m_licenceScreen.render(renderer);
			break;
		}
		case GameState::Splash:
		{
			m_splashScreen.render(renderer);
			break;
		}
		case GameState::MainMenu:
		{
			m_mainMenuScreen.render(renderer);
			break;
		}
		case GameState::Options:
		{
			m_optionsScreen.render(renderer);
			break;
		}
		case GameState::Help:
		{
			m_helpScreen.render(renderer);
			break;
		}
	}

	// Drawing occurs here

	//

	SDL_RenderPresent(renderer);
}

/// <summary>
/// 
/// </summary>
void Game::clean()
{
	SDL_DestroyWindow(window);
	//SDL_DestoryRenderer(renderer);
	SDL_Quit();
	std::cout << "Game clened!" << std::endl;
}