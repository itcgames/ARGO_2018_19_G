//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:21 4 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <iostream>

#include "SDL.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height);
	void run();

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return m_isRunning; };
	

private:
	bool m_isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

#endif // !GAME_H