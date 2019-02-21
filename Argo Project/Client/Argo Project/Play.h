#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "MenuManager.h"
#include "ECS.h"
class PlayScreen
{
public:
	PlayScreen(SDL_Renderer* renderer);
	~PlayScreen();

	void initialise(SDL_Renderer* renderer);
	void update(GameState *gameState);
	void render(SDL_Renderer *renderer);
	void initSprites(SDL_Renderer *renderer);
	void createObstacle();
private:
	Entity* m_player;
	Entity* m_obstacle;

	SDL_Event m_event;

	SDL_Texture* m_backgroundTxt;
	SDL_Texture* m_playerTxt;
	SDL_Texture* m_obstacleTxt;
	SDL_Texture* m_platformTxt;

	SDL_Rect m_obstacleRect;
	SDL_Rect* m_backgroundPos;
	SDL_Rect* m_playerRect;

	Entity *player;

	//
	PositionComponent* m_pc;
	SpriteComponent* m_sc;
	//
	JumpingSystem m_js;
	RenderSystem* m_rs;

};