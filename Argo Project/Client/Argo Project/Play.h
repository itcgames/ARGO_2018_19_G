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
	void update(GameState *gameState, float deltaTime);
	void render(SDL_Renderer *renderer);
	void initSprites(SDL_Renderer *renderer);
private:
	Entity * m_player;
	SDL_Event m_event;
	SDL_Texture* m_backgroundTxt;
	SDL_Texture* m_playerTxt;
	SDL_Rect* m_backgroundPos;
	SDL_Rect* m_playerRect;
	//
	SDL_Texture* m_coinTxtOne;
	SDL_Texture* m_coinTxtTwo;
	SDL_Texture* m_coinTxtThree;
	//
	SDL_Rect* m_coinRectOne;
	SDL_Rect* m_coinRectTwo;
	SDL_Rect* m_coinRectThree;
	//
	Entity *player;
	//
	Entity *m_coins[12];

	//
	PositionComponent* m_pc;
	SpriteComponent* m_sc;
	//
	CoinComponent* m_ccOne;
	CoinComponent* m_ccTwo;
	CoinComponent* m_ccThree;
	//
	PositionComponent* m_pcCoinOne;
	PositionComponent* m_pcCoinTwo;
	PositionComponent* m_pcCoinThree;
	//
	JumpingSystem m_js;
	RenderSystem* m_rs;

};