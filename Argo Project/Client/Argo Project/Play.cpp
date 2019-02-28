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

	m_score = 0;

	initSprites(renderer);
	m_obstacles.clear();
	m_coins.clear();
	m_platforms.clear();

	m_rs = new RenderSystem();
	m_cs = new CollisionSystem();

	m_player = new Entity();
	m_ai = new Entity();
	m_groundPlatform = new Entity();
	m_pc = new PositionComponent(Vector2(m_playerRect->x, m_playerRect->y), 1);
	m_sc = new SpriteComponent(m_playerTxt, m_playerRect, 2);
	PositionComponent* aiPos = new PositionComponent(Vector2(m_aiRect->x, m_aiRect->y), 1);
	SpriteComponent* aiSprite = new SpriteComponent(m_aiTxt, m_aiRect, 2);

	m_player->addComponent<PositionComponent>(m_pc, 1);
	m_player->addComponent<SpriteComponent>(m_sc, 2);
	m_ai->addComponent<PositionComponent>(aiPos, 1);
	m_ai->addComponent<SpriteComponent>(aiSprite, 2);

	m_rs->addEntity(m_ai);
	m_rs->addEntity(m_player);
	m_js.addEntity(m_player);

	m_nonPlayerMovementSystem = new NonPlayerMovementSystem();
	m_decisionNodeSystem = new DecisionNodeSystem();
	m_aiJumpingSystem = new AIJumpingSystem();

	m_aiJumpingSystem->addEntity(m_ai);

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
	m_groundPlatform->addComponent<PositionComponent>(pc, 1);
	m_groundPlatform->addComponent<SpriteComponent>(sc, 2);
	m_rs->addEntity(m_groundPlatform);

	int ran = rand() % 3 + 1;
	createWave(ran);

	m_waveInterval = 0;

	m_lives = 3;
	m_activeHealth = m_fullHealth;
}

void PlayScreen::update(GameState* gameState, float deltaTime, SDL_Renderer* renderer)
{
	m_js.update(deltaTime);

	m_waveInterval++;

	if (m_waveInterval > 20000)
	{
		int randNum = rand() % 3 + 1;

		createWave(1);
		m_waveInterval = 0;
	}

	collisionsAndClearing();

	m_nonPlayerMovementSystem->update(deltaTime);

	m_decisionNodeSystem->update(deltaTime);

	m_aiJumpingSystem->update(deltaTime);

	m_playerRect->y = m_player->getComponent<PositionComponent>(1)->getPosition().y;
	m_aiRect->y = m_ai->getComponent<PositionComponent>(1)->getPosition().y;
	switch (m_lives)
	{
	case 2: 
		m_activeHealth = m_damagedHealth;
		break;
	case 1:
		m_activeHealth = m_lowHealth;
		break;
	case 0:
		
		*gameState = GameState::MainMenu;
		initialise(renderer);
	default:
		break;
	}
}

void PlayScreen::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_backgroundTxt, NULL, m_backgroundPos);

	SDL_RenderCopy(renderer, m_activeHealth, NULL, m_healthbarRect);

	for (int i = 0; i < m_coins.size(); i++)
	{
		m_rs->renderImage(renderer, m_coins[i]->getComponent<SpriteComponent>(2));
	}

	for (int i = 0; i < m_obstacles.size(); i++)
	{
		m_rs->renderImage(renderer, m_obstacles[i]->getComponent<SpriteComponent>(2));
	}

	for (int i = 0; i < m_platforms.size(); i++)
	{
		m_rs->renderImage(renderer, m_platforms[i]->getComponent<SpriteComponent>(2));
	}

	m_rs->render(renderer);
}


void PlayScreen::initSprites(SDL_Renderer *renderer)
{
	//
	SDL_Surface* backgroundSurface = IMG_Load("ASSETS/8.png");
	SDL_Surface* playerSurface = IMG_Load("resources/Player.png");
	SDL_Surface* aiSurface = IMG_Load("resources/AI.png");
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
	SDL_Surface* fullHealthSurface = IMG_Load("ASSETS/FullHealthBar.png");
	SDL_Surface* damagedHealthbarSurface = IMG_Load("ASSETS/DamagedHealthBar.png");
	SDL_Surface* lowHealthbarSurface = IMG_Load("ASSETS/HeavyDamagedHealthBar.png");

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
	m_aiTxt = SDL_CreateTextureFromSurface(renderer, aiSurface);
	//
	m_coinTxtOne = SDL_CreateTextureFromSurface(renderer, coinOneSurface);
	m_coinTxtTwo = SDL_CreateTextureFromSurface(renderer, coinTwoSurface);
	m_coinTxtThree = SDL_CreateTextureFromSurface(renderer, coinThreeSurface);
	//
	m_platformText = SDL_CreateTextureFromSurface(renderer, platformSurface);
	//
	m_fullHealth = SDL_CreateTextureFromSurface(renderer, fullHealthSurface);
	m_damagedHealth = SDL_CreateTextureFromSurface(renderer, damagedHealthbarSurface);
	m_lowHealth = SDL_CreateTextureFromSurface(renderer, lowHealthbarSurface);

	m_healthbarRect = new SDL_Rect();
	m_healthbarRect->x = 100; m_healthbarRect->y = 100;
	m_healthbarRect->w = 500; m_healthbarRect->h = 100;

	m_backgroundPos = new SDL_Rect();
	m_backgroundPos->x = 0; m_backgroundPos->y = 0;
	m_backgroundPos->w = 1920; m_backgroundPos->h = 1080;
	//
	m_playerRect = new SDL_Rect();
	m_playerRect->x = 100; m_playerRect->y = 770;
	m_playerRect->w = 100; m_playerRect->h = 150;

	m_aiRect = new SDL_Rect();
	m_aiRect->x = 300; m_aiRect->y = 770;
	m_aiRect->w = 100; m_aiRect->h = 150;
}


void PlayScreen::createObstacle(SDL_Rect* rect)
{
	Entity* obstacle = new Entity();

	int randNum = rand() % m_obstacleTextures.size();

	if (randNum == 2)
	{
		rect->h = 75;
		rect->y += 25;
	}

	PositionComponent* obsPos = new PositionComponent(Vector2(rect->x, rect->y), 1);

	SpriteComponent* spriteComponent = new SpriteComponent(m_obstacleTextures[randNum], rect, 2);

	obstacle->addComponent<PositionComponent>(obsPos, 1);
	obstacle->addComponent<SpriteComponent>(spriteComponent, 2);

	m_nonPlayerMovementSystem->addEntity(obstacle);

	m_obstacles.push_back(obstacle);
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
	m_nonPlayerMovementSystem->addEntity(m_coin);

	m_coins.push_back(m_coin);
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

	m_nonPlayerMovementSystem->addEntity(platform);

	m_platforms.push_back(platform);
}

void PlayScreen::createDecisionNode(SDL_Point* point)
{
	Entity* node = new Entity();

	PositionComponent* pc = new PositionComponent(Vector2(point->x, point->y), 1);

	node->addComponent<PositionComponent>(pc, 1);

	m_decisionNodeSystem->addEntity(node);

	m_decisionNodes.push_back(node);

	std::cout << "node created" << std::endl;
}

void PlayScreen::createWave(int type)
{
	switch (type)
	{
	case 1:
	{
		SDL_Rect * c1coinRect = new SDL_Rect();
		c1coinRect->x = 1920; c1coinRect->y = 830;
		c1coinRect->w = 70; c1coinRect->h = 70;
		createCoin(c1coinRect);

		SDL_Rect* c1plRect = new SDL_Rect();
		c1plRect->x = 2220; c1plRect->y = 680;
		c1plRect->w = 500; c1plRect->h = 50;
		createPlatform(c1plRect);

		SDL_Point* c1node1Point = new SDL_Point();
		c1node1Point->x = 2350; c1node1Point->y = 580;
		createDecisionNode(c1node1Point);

		SDL_Rect* c1obsrect = new SDL_Rect();
		c1obsrect->x = 2420; c1obsrect->y = 580;
		c1obsrect->w = 100; c1obsrect->h = 100;
		createObstacle(c1obsrect);

		SDL_Point* c1node1Point2 = new SDL_Point();
		c1node1Point2->x = 2950; c1node1Point2->y = 830;
		createDecisionNode(c1node1Point2);

		SDL_Rect* c1obsrect2 = new SDL_Rect();
		c1obsrect2->x = 3050; c1obsrect2->y = 830;
		c1obsrect2->w = 100; c1obsrect2->h = 100;
		createObstacle(c1obsrect2);
		break;
	}
	
	case 2:
	{
		SDL_Rect * c2plRect = new SDL_Rect();
		c2plRect->x = 1920; c2plRect->y = 680;
		c2plRect->w = 600; c2plRect->h = 50;
		createPlatform(c2plRect);


		SDL_Rect * c2plRect2 = new SDL_Rect();
		c2plRect2->x = 2920; c2plRect2->y = 680;
		c2plRect2->w = 600; c2plRect2->h = 50;
		createPlatform(c2plRect2);

		SDL_Rect * c2coinRect = new SDL_Rect();
		c2coinRect->x = 1920; c2coinRect->y = 830;
		c2coinRect->w = 70; c2coinRect->h = 70;
		createCoin(c2coinRect);

		SDL_Rect * c2coinRect2 = new SDL_Rect();
		c2coinRect2->x = 2220; c2coinRect2->y = 580;
		c2coinRect2->w = 70; c2coinRect2->h = 70;
		createCoin(c2coinRect2);

		SDL_Rect* c2obsrect = new SDL_Rect();
		c2obsrect->x = 2420; c2obsrect->y = 580;
		c2obsrect->w = 100; c2obsrect->h = 100;
		createObstacle(c2obsrect);

		SDL_Rect* c2obsrect2 = new SDL_Rect();
		c2obsrect2->x = 3420; c2obsrect2->y = 580;
		c2obsrect2->w = 100; c2obsrect2->h = 100;
		createObstacle(c2obsrect2);
		break;
	}

	case 3:
	{
		SDL_Rect * c3plRect = new SDL_Rect();
		c3plRect->x = 2320; c3plRect->y = 680;
		c3plRect->w = 600; c3plRect->h = 50;
		createPlatform(c3plRect);

		SDL_Rect * c3coinRect = new SDL_Rect();
		c3coinRect->x = 1920; c3coinRect->y = 830;
		c3coinRect->w = 70; c3coinRect->h = 70;
		createCoin(c3coinRect);

		SDL_Rect * c3coinRect2 = new SDL_Rect();
		c3coinRect2->x = 2320; c3coinRect2->y = 580;
		c3coinRect2->w = 70; c3coinRect2->h = 70;
		createCoin(c3coinRect2);

		SDL_Rect * c3obsRect = new SDL_Rect();
		c3obsRect->x = 2720; c3obsRect->y = 580;
		c3obsRect->w = 100; c3obsRect->h = 100;
		createObstacle(c3obsRect);

		SDL_Rect * c3coinRect4 = new SDL_Rect();
		c3coinRect4->x = 3170; c3coinRect4->y = 830;
		c3coinRect4->w = 70; c3coinRect4->h = 70;
		createCoin(c3coinRect4);

		SDL_Rect * c3coinRect5 = new SDL_Rect();
		c3coinRect5->x = 2620; c3coinRect5->y = 830;
		c3coinRect5->w = 70; c3coinRect5->h = 70;
		createCoin(c3coinRect5);

		break;
	}
	}
}

void PlayScreen::collisionsAndClearing()
{
	for (int i = 0; i < m_platforms.size(); i++)
	{
		//
		if (m_cs->intersectRect(m_player, m_groundPlatform) == true)
		{
			m_js.setGrounded(true);
			m_player->getComponent<PositionComponent>(1)->setPosition(Vector2(m_player->getComponent<PositionComponent>(1)->getPosition().x,
				(m_groundPlatform->getComponent<SpriteComponent>(2)->getRect()->y - m_player->getComponent<SpriteComponent>(2)->getRect()->h) - 1));
		}

		else if (m_cs->intersectRect(m_player, m_platforms[i]) == true)
		{
			m_js.setGrounded(true);
			m_player->getComponent<PositionComponent>(1)->setPosition(Vector2(m_player->getComponent<PositionComponent>(1)->getPosition().x,
				(m_platforms[i]->getComponent<SpriteComponent>(2)->getRect()->y - m_player->getComponent<SpriteComponent>(2)->getRect()->h) - 1));
		}

		if (m_player->getComponent<PositionComponent>(1)->getPosition().y < 480 &&
			m_player->getComponent<PositionComponent>(1)->getPosition().x > m_platforms[i]->getComponent<SpriteComponent>(2)->getRect()->x + m_platforms[i]->getComponent<SpriteComponent>(2)->getRect()->w)
		{
			m_js.setGrounded(false);
		}

		if (m_cs->intersectRect(m_ai, m_groundPlatform) == true)
		{
			m_aiJumpingSystem->setGrounded(true);
			m_ai->getComponent<PositionComponent>(1)->setPosition(Vector2(m_ai->getComponent<PositionComponent>(1)->getPosition().x,
				(m_groundPlatform->getComponent<SpriteComponent>(2)->getRect()->y - m_ai->getComponent<SpriteComponent>(2)->getRect()->h) - 1));
		}

		else if (m_cs->intersectRect(m_ai, m_platforms[i]) == true)
		{
			m_aiJumpingSystem->setGrounded(true);
			m_player->getComponent<PositionComponent>(1)->setPosition(Vector2(m_ai->getComponent<PositionComponent>(1)->getPosition().x,
				(m_platforms[i]->getComponent<SpriteComponent>(2)->getRect()->y - m_ai->getComponent<SpriteComponent>(2)->getRect()->h) - 1));
		}

		if (m_ai->getComponent<PositionComponent>(1)->getPosition().y < 480 &&
			m_ai->getComponent<PositionComponent>(1)->getPosition().x > m_platforms[i]->getComponent<SpriteComponent>(2)->getRect()->x + m_platforms[i]->getComponent<SpriteComponent>(2)->getRect()->w)
		{
			m_aiJumpingSystem->setGrounded(false);
		}

		if (m_platforms[i]->getComponent<PositionComponent>(1)->getPosition().x + m_platforms[i]->getComponent<SpriteComponent>(2)->getRect()->w < 0)
		{
			m_platforms[i] = nullptr;
			m_platforms.erase(m_platforms.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < m_coins.size(); i++)
	{
		bool destroy = false;
		if (m_cs->intersectRect(m_player, m_coins[i]) == true)
		{
			m_score += m_coins[i]->getComponent<CoinComponent>(3)->getScore();

			std::cout << "Score: " + std::to_string(m_score) << std::endl;

			destroy = true;
		}

		if (m_coins[i]->getComponent<PositionComponent>(1)->getPosition().x + m_coins[i]->getComponent<SpriteComponent>(2)->getRect()->w < 0)
		{
			destroy = true;
		}

		if (destroy)
		{
			m_coins[i] = nullptr;
			m_coins.erase(m_coins.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < m_obstacles.size(); i++)
	{
		if (m_cs->intersectRect(m_player, m_obstacles[i]))
		{
			m_lives -= 1;
		}

		if (m_obstacles[i]->getComponent<PositionComponent>(1)->getPosition().x + m_obstacles[i]->getComponent<SpriteComponent>(2)->getRect()->w < 0 || m_cs->intersectRect(m_player, m_obstacles[i]))
		{
			m_obstacles[i] = nullptr;
			m_obstacles.erase(m_obstacles.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < m_decisionNodes.size(); i++)
	{
		//
		if (m_cs->decisionPointIntersect(m_ai, m_decisionNodes[i]))
		{

			m_aiJumpingSystem->setJump(true);
		}
	}
}