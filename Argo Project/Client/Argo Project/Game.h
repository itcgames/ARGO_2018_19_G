//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:21 4 Feburary 2019
// Finished at
// Time taken:
// Known bugs:


#include <stdio.h>
#include <iostream>

#include "SDL.h"

#include "MenuManager.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height);

	void handleEvents();
	void run();
	void update();
	void render();
	void clean();

	bool running() { return m_isRunning; };
	

private:
	GameState m_currentGamestate;
	LicenceScreen m_licenceScreen;
	SplashScreen m_splashScreen;
	MainMenuScreen m_mainMenuScreen;
	OptionsScreen m_optionsScreen;
	HelpScreen m_helpScreen;

	SDL_Window *window;
	bool m_isRunning;
	SDL_Renderer *renderer;
};