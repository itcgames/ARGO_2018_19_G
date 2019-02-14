#pragma once
#include <SDL.h>
class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void update();
	void render(SDL_Renderer *renderer);
};

