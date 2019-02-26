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

	m_rs = new RenderSystem();
	m_cs = new CollisionSystem();

	m_player = new Entity();
	m_pc = new PositionComponent(Vector2(m_playerRect->x, m_playerRect->y), 1);
	m_sc = new SpriteComponent(m_playerTxt, m_playerRect, 2);

	m_player->addComponent<PositionComponent>(m_pc, 1);
	m_player->addComponent<SpriteComponent>(m_sc, 2);
	m_rs->addEntity(m_player);
	m_js.addEntity(m_player);

	m_nonPlayerMovementSystem = new NonPlayerMovementSystem();

	SDL_Rect* coinRect = new SDL_Rect();
	coinRect->x = 1920; coinRect->y = 780;
	coinRect->w = 70; coinRect->h = 70;
	createCoin(coinRect);
	
	SDL_Rect* ground = new SDL_Rect();
	ground->x = 0; ground->y = 930;
	ground->w = 1920; ground->h = 50;

	Entity* groundPlatform = new Entity();
	//
	PositionComponent* pc = new PositionComponent(Vector2(ground->x, ground->y), 1);
	//
	m_plc = new PlatformComponent(m_platformText, ground, 4);
	SpriteComponent* sc = new SpriteComponent(m_platformText, ground, 2);
	//
	groundPlatform->addComponent<PositionComponent>(pc, 1);
	groundPlatform->addComponent<SpriteComponent>(sc, 2);
	m_rs->addEntity(groundPlatform);
	m_platforms.push_back(groundPlatform);


	SDL_Rect* plRect = new SDL_Rect();
	plRect->x = 100; plRect->y = 930;
	plRect->w = 250; plRect->h = 50;
	//createPlatform(plRect);

	SDL_Rect* rect = new SDL_Rect();
	rect->x = 1920; rect->y = 830;
	rect->w = 100; rect->h = 100;
	createObstacle(rect);

	std::cout << m_player->getComponent<PositionComponent>(1)->getPosition().y << std::endl;
}

void PlayScreen::update(GameState* gameState, float deltaTime)
{
	m_js.update(deltaTime);

	m_nonPlayerMovementSystem->update(deltaTime);
	
	for (int i = 0; i < m_platforms.size(); i++)
	{

		if (m_cs->platformCollisions(m_player, m_platforms[i]) == true)
		{
			m_js.setGrounded(true);
			m_player->getComponent<PositionComponent>(1)->setPosition(Vector2(m_player->getComponent<PositionComponent>(1)->getPosition().x,
				(m_platforms[i]->getComponent<SpriteComponent>(2)->getRect()->y - m_player->getComponent<SpriteComponent>(2)->getRect()->h) - 1));
		}
	}

	m_playerRect->y = m_player->getComponent<PositionComponent>(1)->getPosition().y;
}

void PlayScreen::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_backgroundTxt, NULL, m_backgroundPos);

	m_rs->render(renderer);
}


void PlayScreen::initSprites(SDL_Renderer *renderer)
{
	//
	SDL_Surface* backgroundSurface = IMG_Load("ASSETS/8.png");
	SDL_Surface* playerSurface = IMG_Load("resources/Player.png");
	//
	SDL_Surface* coinOneSurface = IMG_Load("resources/SmallCoin.png");
	SDL_Surface* coinTwoSurface = IMG_Load("resources/LargeCoin.png");
	SDL_Surface* coinThreeSurface = IMG_Load("resources/Wallet.png");
	//
	SDL_Surface* platformSurface = IMG_Load("resources/platform.png");
	//
	SDL_Surface* wiresSurface = IMG_Load("ASSETS/Hazard1_LargeLoseWires.png");
	SDL_Surface* thumbTacSurface = IMG_Load("ASSETS/Hazard3_ThumbTak.png");
	SDL_Surface* mouseSurface = IMG_Load("ASSETS/Obstacle_Mouse.png");
	SDL_Surface* splintersSurface = IMG_Load("ASSETS/Hazard4_Splinters2.png");
	//

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
	//
	m_coinTxtOne = SDL_CreateTextureFromSurface(renderer, coinOneSurface);
	m_coinTxtTwo = SDL_CreateTextureFromSurface(renderer, coinTwoSurface);
	m_coinTxtThree = SDL_CreateTextureFromSurface(renderer, coinThreeSurface);
	//
	m_platformText = SDL_CreateTextureFromSurface(renderer, platformSurface);
	//
	m_backgroundPos = new SDL_Rect();
	m_backgroundPos->x = 0; m_backgroundPos->y = 0;
	m_backgroundPos->w = 1920; m_backgroundPos->h = 1080;
	//
	m_playerRect = new SDL_Rect();
	m_playerRect->x = 100; m_playerRect->y = 770;
	m_playerRect->w = 100; m_playerRect->h = 150;
}


void PlayScreen::createObstacle(SDL_Rect* rect)
{
	Entity* m_obstacle = new Entity();
	PositionComponent* obsPos = new PositionComponent(Vector2(rect->x, rect->y), 1);

	int randNum = rand() % m_obstacleTextures.size();

	SpriteComponent* spriteComponent = new SpriteComponent(m_obstacleTextures[randNum], rect, 2);

	m_obstacle->addComponent<PositionComponent>(obsPos, 1);
	m_obstacle->addComponent<SpriteComponent>(spriteComponent, 2);

	m_rs->addEntity(m_obstacle);
	m_nonPlayerMovementSystem->addEntity(m_obstacle);
}

void PlayScreen::createCoin(SDL_Rect* rect)
{
	int coinType = rand() % 3 + 1;

	Entity* m_coin = new Entity();

	//
	if (coinType == 1)
	{
		CoinComponent* cc1 = new CoinComponent(m_coinTxtOne, rect, 3, 1);
		SpriteComponent* rc1 = new SpriteComponent(m_coinTxtOne, rect, 2);

		m_coin->addComponent<CoinComponent>(cc1, 3);
		m_coin->addComponent<SpriteComponent>(rc1, 2);
	}
	//
	if (coinType == 2)
	{
		CoinComponent* cc2 = new CoinComponent(m_coinTxtTwo, rect, 3, 2);
		SpriteComponent* rc2 = new SpriteComponent(m_coinTxtTwo, rect, 2);

		m_coin->addComponent<CoinComponent>(cc2, 3);
		m_coin->addComponent<SpriteComponent>(rc2, 2);
	}
	//
	if (coinType == 3)
	{
		CoinComponent* cc3 = new CoinComponent(m_coinTxtThree, rect, 3, 3);
		SpriteComponent* rc3 = new SpriteComponent(m_coinTxtThree, rect, 2);

		m_coin->addComponent<CoinComponent>(cc3, 3);
		m_coin->addComponent<SpriteComponent>(rc3, 2);
	}

	PositionComponent* pc = new PositionComponent(Vector2(rect->x, rect->y), 1);
	m_coin->addComponent<PositionComponent>(pc, 1);
	m_rs->addEntity(m_coin);
	m_nonPlayerMovementSystem->addEntity(m_coin);
}

void PlayScreen::createPlatform(SDL_Rect* rect)
{
	Entity* platform = new Entity();
	//
	PositionComponent* pc = new PositionComponent(Vector2(rect->x, rect->y), 1);
	//
	m_plc = new PlatformComponent(m_platformText, rect, 4);
	SpriteComponent* sc = new SpriteComponent(m_platformText, rect, 2);
	//
	platform->addComponent<PositionComponent>(pc, 1);
	platform->addComponent<SpriteComponent>(sc, 2);
	m_rs->addEntity(platform);
	m_nonPlayerMovementSystem->addEntity(platform);
	m_platforms.push_back(platform);
}