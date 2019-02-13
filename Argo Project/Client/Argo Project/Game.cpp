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

SDL_Event Game::m_event;

/// <summary>
/// 
/// </summary>
Game::Game()
{
	m_cnt = 0;
	//m_player(m_manager.addEntity());
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

	//
	if (fullScreen == true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

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
	}

	//
	else
	{
		m_isRunning = false;
	}



	m_player = new Player(renderer, 100, 100, 50, 100);

	
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

//
void Game::run()
{
	update();
	render();

	//
	/*if (window == NULL)
	{
		std::cout << "Window Creation Error: " << SDL_GetError() << std::endl;
	}
	//
	else
	{

		// Window Created
			windowSurface = SDL_GetWindowSurface(window);
			imageSurface = SDL_LoadBMP("Assets/Block.bmp");

			//
			if (imageSurface == NULL)
			{
				std::cout << "Image loading Error: " << SDL_GetError() << std::endl;
			}
			//
			else 
			{
				SDL_BlitSurface(imageSurface, NULL, windowSurface, m_rect);
				SDL_UpdateWindowSurface(window);
				SDL_Delay(2000);
			}

	}	*/
}

//
void Game::update() 
{
	m_player->update();

	m_cnt++;
	std::cout << m_cnt << std::endl;
}



/// <summary>
/// 
/// </summary>
void Game::render() 
{
	SDL_RenderClear(renderer);

	// Drawing occurs here
	m_player->render(renderer);
	//

	SDL_RenderPresent(renderer);
}

/// <summary>
/// 
/// </summary>
void Game::clean()
{
	//SDL_FreeSurface(imageSurface);
	//imageSurface = nullptr;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	//window = nullptr;
	//windowSurface = nullptr;
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}