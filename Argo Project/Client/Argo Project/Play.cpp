#include "Play.h"



PlayScreen::PlayScreen(SDL_Renderer* renderer)
{
	initialise(renderer);
}


PlayScreen::~PlayScreen()
{
}

void PlayScreen::initialise(SDL_Renderer* renderer)
{
	initSprites(renderer);
	Entity* m_player = new Entity();

	m_pc = new PositionComponent(Vector2(m_playerRect->x, m_playerRect->y), 1);
	m_sc = new SpriteComponent(m_playerTxt, m_playerRect, 2);

	m_player->addComponent<PositionComponent>(m_pc, 1);
	m_player->addComponent<SpriteComponent>(m_sc, 2);

	m_rs = new RenderSystem();
	//m_rs->addEntity(m_player);

	SDL_Rect* rect = new SDL_Rect();
	rect->x = 200; rect->y = 780;
	rect->w = 100; rect->h = 100;
	createObstacle(rect);
}

void PlayScreen::update(GameState* gameState)
{
	/*while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type)
		{
		case SDL_KEYDOWN:
			*gameState = GameState::MainMenu;
		}
	}*/

}

void PlayScreen::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_backgroundTxt, NULL, m_backgroundPos);

	m_rs->render(renderer);
}


void PlayScreen::initSprites(SDL_Renderer *renderer)
{
	SDL_Surface* backgroundSurface = IMG_Load("ASSETS/8.png");
	SDL_Surface* playerSurface = IMG_Load("resources/Player.png");
	SDL_Surface* wiresSurface = IMG_Load("ASSETS/Hazard1_LargeLoseWires.png");
	SDL_Surface* thumbTacSurface = IMG_Load("ASSETS/Hazard3_ThumbTak.png");
	SDL_Surface* mouseSurface = IMG_Load("ASSETS/Obstacle_Mouse.png");
	SDL_Surface* splintersSurface = IMG_Load("ASSETS/Hazard4_Splinters2.png");

	m_wiresTxt = SDL_CreateTextureFromSurface(renderer, wiresSurface);
	m_obstacleTextures.push_back(m_wiresTxt);
	m_thumbtacTxt = SDL_CreateTextureFromSurface(renderer, thumbTacSurface);
	m_obstacleTextures.push_back(m_thumbtacTxt);
	m_mouseTxt = SDL_CreateTextureFromSurface(renderer, mouseSurface);
	m_obstacleTextures.push_back(m_mouseTxt);
	m_splintersTxt = SDL_CreateTextureFromSurface(renderer, splintersSurface);
	m_obstacleTextures.push_back(m_splintersTxt);

	m_backgroundTxt = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
	m_playerTxt = SDL_CreateTextureFromSurface(renderer, playerSurface);
	
	SDL_FreeSurface(backgroundSurface);
	SDL_FreeSurface(playerSurface);

	m_backgroundPos = new SDL_Rect();
	m_backgroundPos->x = 0;m_backgroundPos->y = 0;
	m_backgroundPos->w = 1920;m_backgroundPos->h = 1080;

	m_playerRect = new SDL_Rect();
	m_playerRect->x = 100; m_playerRect->y = 780;
	m_playerRect->w = 100; m_playerRect->h = 150;
}

void PlayScreen::createObstacle(SDL_Rect* rect)
{
	Entity* m_obstacle = new Entity();
	PositionComponent* obsPos = new PositionComponent(Vector2(rect->x, rect->y), 1);
	int ranNum = rand() % m_obstacleTextures.size();
	SpriteComponent* spriteComponent = new SpriteComponent(m_thumbtacTxt, rect, 2);

	m_obstacle->addComponent<PositionComponent>(obsPos, 1);
	m_obstacle->addComponent<SpriteComponent>(m_sc, 2);

	m_rs->addEntity(m_obstacle);
}