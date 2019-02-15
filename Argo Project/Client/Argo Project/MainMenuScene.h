#pragma once
#include <SDL.h>
class MainMenuScreen
{
public:
	MainMenuScreen(SDL_Renderer* renderer);
	~MainMenuScreen();

	void initialise(SDL_Renderer* renderer);
	void update();
	void render(SDL_Renderer *renderer);
};

