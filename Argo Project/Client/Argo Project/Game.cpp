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
	//
	m_deltaTime = 0.0;
	m_now = SDL_GetTicks();
	m_last = 0;
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
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	int flags = 0;

	if (fullScreen == true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		m_licenceScreen = new LicenceScreen(renderer);
		m_splashScreen = new SplashScreen(renderer);
		m_mainMenuScreen = new MainMenuScreen(renderer);
		m_helpScreen = new HelpScreen(renderer);
		m_playScreen = new PlayScreen(renderer);
		m_creditScreen = new CreditsScreen(renderer);

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
	//
	const int m_FPS = 30;
	const int m_frameDelay = 1000 / m_FPS;
	//
	int m_frameStart = 0, m_frameTime = 0;

	while (m_isRunning)
	{
		m_now = SDL_GetTicks();

		if (m_now > m_last)
		{
			m_deltaTime = ((float)(m_now - m_last) / 100.f);
			m_last = m_now;
		}
		
		update(m_deltaTime);
		render();

		m_frameTime = SDL_GetTicks() - m_frameStart;

		//
		if (m_frameDelay > m_frameTime)
		{
			SDL_Delay(m_frameDelay - m_frameTime);
		}
	}
}

//
void Game::update(float deltaTime)
{
	switch (m_currentGamestate)
	{
		case GameState::Licence:
		{
			m_licenceScreen->update(&m_currentGamestate);
			break;
		}
		case GameState::Splash:
		{
			m_splashScreen->update(&m_currentGamestate);
			break;
		}
		case GameState::MainMenu:
		{
			m_mainMenuScreen->update(&m_currentGamestate);
			break;
		}
		case GameState::Help:
		{
			m_helpScreen->update(&m_currentGamestate);
			break;
		}

		case GameState::Credits:
		{
			m_creditScreen->update(&m_currentGamestate);
			break;
		}

		case GameState::Play:
		{
			m_playScreen->update(&m_currentGamestate, deltaTime, renderer);
			break;
		}
	}
}

void Game::render() 
{
	SDL_RenderClear(renderer);

	// Drawing occurs here
	switch (m_currentGamestate)
	{
		case GameState::Licence:
		{
			m_licenceScreen->render(renderer);
			break;
		}
		case GameState::Splash:
		{
			m_splashScreen->render(renderer);
			break;
		}
		case GameState::MainMenu:
		{
			m_mainMenuScreen->render(renderer);
			break;
		}
		case GameState::Credits:
		{
			m_creditScreen->render(renderer);
			break;
		}
		case GameState::Help:
		{
			m_helpScreen->render(renderer);
			break;
		}
		case GameState::Play:
		{
			m_playScreen->render(renderer);
			break;
		}
	}

	//
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}