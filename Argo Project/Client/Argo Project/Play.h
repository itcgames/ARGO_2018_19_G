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
	void update(GameState *gameState, float deltaTime, SDL_Renderer* renderer);
	void render(SDL_Renderer *renderer);
	void initSprites(SDL_Renderer *renderer);
	void createObstacle(SDL_Rect* rect);
	void createCoin(SDL_Rect* rect);
	void createPlatform(SDL_Rect* rect);
	void createDecisionNode(SDL_Point* point);
	void createWave(int type);
	void collisionsAndClearing();
private:
	Entity * m_player;
	Entity* m_ai;
	SDL_Event m_event;

	SDL_Texture* m_backgroundTxt;

	SDL_Texture* m_playerTxt;
	SDL_Texture* m_aiTxt;

	SDL_Texture* m_wiresTxt;
	SDL_Texture* m_thumbtacTxt;
	SDL_Texture* m_mouseTxt;
	SDL_Texture* m_splintersTxt;

	SDL_Texture* m_coinTxtOne;
	SDL_Texture* m_coinTxtTwo;
	SDL_Texture* m_coinTxtThree;

	SDL_Texture* m_platformText;

	SDL_Texture* m_activeHealth;
	SDL_Texture* m_fullHealth;
	SDL_Texture* m_damagedHealth;
	SDL_Texture* m_lowHealth;
	SDL_Rect* m_healthbarRect;

	//
	SDL_Rect* m_backgroundPos;
	SDL_Rect* m_playerRect;
	SDL_Rect* m_aiRect;
	//
	std::vector<SDL_Texture*> m_obstacleTextures;
	std::vector<Entity*> m_obstacles;
	std::vector<Entity*> m_platforms;
	std::vector<Entity*> m_coins;
	std::vector<Entity*> m_decisionNodes;
	//
	Entity* m_groundPlatform;

	//
	PositionComponent* m_pc;
	SpriteComponent* m_sc;
	//
	PlatformComponent* m_plc;
	
	//
	JumpingSystem m_js;
	RenderSystem* m_rs;
	CollisionSystem* m_cs;
	NonPlayerMovementSystem* m_nonPlayerMovementSystem;
	DecisionNodeSystem* m_decisionNodeSystem;
	AIJumpingSystem* m_aiJumpingSystem;

	int m_waveInterval;

	int m_score;

	int m_lives;
	int m_invincibilityTimer;
	bool m_invincible;
};