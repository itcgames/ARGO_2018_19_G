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

#include "MenuManager.h"
#include "LicenceScreen.h"
#include "SplashScreen.h"
#include "MainMenuScene.h"
#include "OptionsScreen.h"
#include "HelpScreen.h"

#include "ECS.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);

	void handleEvents();
	void run();
	void update(float deltaTime);
	void render();
	void clean();

	bool running() { return m_isRunning; };
	

private:
	GameState m_currentGamestate;
	LicenceScreen* m_licenceScreen;
	SplashScreen* m_splashScreen;
	MainMenuScreen* m_mainMenuScreen;
	OptionsScreen* m_optionsScreen;
	HelpScreen* m_helpScreen;

	SDL_Window *window;
	bool m_isRunning;
	SDL_Renderer *renderer;

	float m_deltaTime;
	Uint64 m_now, m_last;

	Player *m_player;
	//
	Entity *player;

	//
	PositionComponent *m_pc;
	PositionComponent *pc;
	//
	JumpingSystem m_js;
	RenderSystem m_rs;
};

#endif // !GAME_H