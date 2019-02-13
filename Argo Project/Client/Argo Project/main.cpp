//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:21 4 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#pragma comment(lib, "SDL2.lib")
//#pragma comment(lib, "SDLmain.lib")

#define SDL_MAIN_HANDLED

#include "Game.h"

Game *game = nullptr;

int main(int argc, char* argv[])
{
	//
	const int m_FPS = 60;
	const int m_frameDelay = 1000 / m_FPS;
	//
	int m_frameStart, m_frameTime;

	game = new Game();
	game->init("ARGO SDL project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);

	//
	while (game->running())
	{
		m_frameStart = SDL_GetTicks();

		game->handleEvents();
		game->run();

		m_frameTime = SDL_GetTicks() - m_frameStart;

		//
		if (m_frameDelay > m_frameTime)
		{
			SDL_Delay(m_frameDelay - m_frameTime);
		}
	}

	game->clean();

	return 0;
}