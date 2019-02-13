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
#include "SDL_image.h"

#include "Player.h"


class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	void run();

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return m_isRunning; };
	
	static SDL_Event m_event;

private:
	int m_cnt;
	bool m_isRunning, m_fullScreen;
	SDL_Window *window;
	SDL_Surface *imageSurface;
	SDL_Renderer *renderer;
	
	
	Player *m_player;
};

#endif // !GAME_H