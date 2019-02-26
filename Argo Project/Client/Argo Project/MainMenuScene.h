#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "MenuManager.h"
#include "Vector2.h"
class MainMenuScreen
{
public:
	MainMenuScreen(SDL_Renderer* renderer);
	~MainMenuScreen();

	void initialise(SDL_Renderer* renderer);
	void update(GameState *gameState);
	void render(SDL_Renderer *renderer);
	void initButtons(SDL_Renderer* renderer);

private:
	SDL_Point* mouse;
	SDL_Event m_event;
	SDL_Texture* m_playTxt;
	SDL_Texture* m_optionsTxt;
	SDL_Texture* m_helpTxt;
	SDL_Texture* m_quitTxt;
	SDL_Texture* m_backgroundTxt;
	SDL_Rect* m_backgroundPos;
	SDL_Rect* m_playPos;
	SDL_Rect* m_optionsPos;
	SDL_Rect* m_helpPos;
	SDL_Rect* m_quitPos;
};

