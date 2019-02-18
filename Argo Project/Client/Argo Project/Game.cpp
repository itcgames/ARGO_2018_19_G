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
	m_cnt = 0;
	once = false;
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

	if (once == false)
	{
		//
		m_pc = &PositionComponent(Vector2(50, 100), 1);

		//
		//player = Entity();
		//
		//player.addComponent(m_pc);

		//
		//m_rs.addEntity(player);

		player = new Entity();

		player->addComponent<PositionComponent>(m_pc, 1);

		pc = player->getComponent<PositionComponent>(1);

		players.push_back(*player);

		m_js.addEntity(player);

		once = true;
	}

	std::cout << pc->getPosition().x << std::endl;
	std::cout << pc->getPosition().y << std::endl;

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

	std::cout << pc->getPosition().x << std::endl;
q	std::cout << pc->getPosition().y << std::endl;
}

//
void Game::update() 
{
	updateSystems();

	/*m_cnt++;
	std::cout << m_cnt << std::endl;*/
}

/// <summary>
/// 
/// </summary>
void Game::updateSystems()
{
	m_js.update();
}

/// <summary>
/// 
/// </summary>
void Game::render() 
{
	SDL_RenderClear(renderer);

	// Drawing occurs here

	m_rs.render(renderer);
	//

	SDL_RenderPresent(renderer);
}

/// <summary>
/// 
/// </summary>
void Game::clean()
{
	//SDL_FreeSurface(imageSurface);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}

