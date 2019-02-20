//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:21 4 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#pragma comment(lib,"SDL2.lib") 

#define SDL_MAIN_HANDLED

#include "Game.h"

//Game *game = nullptr;

int main()
{
	Game* game = new Game();
	game->init("SDL", 100, 100, 1920, 1080, false);


	game->run();
	
	return 0;
}