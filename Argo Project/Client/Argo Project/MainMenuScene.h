#pragma once
#include <SDL.h>
class MainMenuScreen
{
public:
	MainMenuScreen();
	~MainMenuScreen();

	void update();
	void render(SDL_Renderer *renderer);
};

