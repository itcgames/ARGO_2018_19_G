#pragma once
#include <SDL.h>
class SplashScreen
{
public:
	SplashScreen(SDL_Renderer* renderer);
	~SplashScreen();

	void initialise(SDL_Renderer* renderer);
	void update();
	void render(SDL_Renderer *renderer);
};

