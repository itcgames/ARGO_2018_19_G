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
	m_player = new Entity();
	m_pc = new PositionComponent(Vector2(m_playerRect->x, m_playerRect->y), 1);
	m_sc = new SpriteComponent(m_playerTxt, m_playerRect, 2);

	m_player->addComponent<PositionComponent>(m_pc, 1);
	m_player->addComponent<SpriteComponent>(m_sc, 2);

	m_js.addEntity(m_player);
	m_rs = new RenderSystem();

	for (int i = 0; i < 12; i++)
	{
		int coinType = rand() % 3 + 1;

		m_coins[i] = new Entity();

		//
		if (coinType == 1)
		{
			m_pcCoinOne = new PositionComponent(Vector2(m_coinRectOne->x, m_coinRectOne->y), 1);
			m_ccOne = new CoinComponent(m_coinTxtOne, m_coinRectOne, 3, 1);

			m_coins[i]->addComponent<PositionComponent>(m_pcCoinOne, 1);
			m_coins[i]->addComponent<CoinComponent>(m_ccOne, 3);
		}
		//
		if (coinType == 2)
		{
			m_pcCoinTwo = new PositionComponent(Vector2(m_coinRectTwo->x, m_coinRectTwo->y), 1);
			m_ccTwo = new CoinComponent(m_coinTxtTwo, m_coinRectTwo, 3, 2);

			m_coins[i]->addComponent<PositionComponent>(m_pcCoinTwo, 1);
			m_coins[i]->addComponent<CoinComponent>(m_ccTwo, 3);
		}
		//
		if (coinType == 3)
		{
			m_pcCoinThree = new PositionComponent(Vector2(m_coinRectThree->x, m_coinRectThree->y), 1);
			m_ccThree = new CoinComponent(m_coinTxtThree, m_coinRectThree, 3, 3);

			m_coins[i]->addComponent<PositionComponent>(m_pcCoinThree, 1);
			m_coins[i]->addComponent<CoinComponent>(m_ccThree, 3);
		}
	}

	std::cout << m_player->getComponent<PositionComponent>(1)->getPosition().y << std::endl;
}

void PlayScreen::update(GameState* gameState, float deltaTime)
{
	m_js.update(deltaTime);
	/*while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type)
		{
		case SDL_KEYDOWN:
			*gameState = GameState::MainMenu;
		}
	}*/

	
	m_playerRect->y = m_player->getComponent<PositionComponent>(1)->getPosition().y;
}

void PlayScreen::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_backgroundTxt, NULL, m_backgroundPos);

	//
	for (int i = 0; i < 12; i++)
	{
		m_rs->renderCoin(renderer, m_coins[i]->getComponent<CoinComponent>(3));
	}

	//
	m_rs->renderImage(renderer, m_player->getComponent<SpriteComponent>(2));
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
	m_backgroundTxt = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
	m_playerTxt = SDL_CreateTextureFromSurface(renderer, playerSurface);
	//
	m_coinTxtOne = SDL_CreateTextureFromSurface(renderer, coinOneSurface);
	m_coinTxtTwo = SDL_CreateTextureFromSurface(renderer, coinTwoSurface);
	m_coinTxtThree = SDL_CreateTextureFromSurface(renderer, coinThreeSurface);
	//
	SDL_FreeSurface(backgroundSurface);
	SDL_FreeSurface(playerSurface);
	SDL_FreeSurface(coinOneSurface);
	SDL_FreeSurface(coinTwoSurface);
	SDL_FreeSurface(coinThreeSurface);
	//
	m_backgroundPos = new SDL_Rect();
	m_backgroundPos->x = 0; m_backgroundPos->y = 0;
	m_backgroundPos->w = 1920; m_backgroundPos->h = 1080;
	//
	m_playerRect = new SDL_Rect();
	m_playerRect->x = 100; m_playerRect->y = 780;
	m_playerRect->w = 100; m_playerRect->h = 150;
	//
	m_coinRectOne = new SDL_Rect();
	m_coinRectOne->x = 150; m_coinRectOne->y = 780;
	m_coinRectOne->w = 70; m_coinRectOne->h = 70;
	//
	m_coinRectTwo = new SDL_Rect();
	m_coinRectTwo->x = 280; m_coinRectTwo->y = 780;
	m_coinRectTwo->w = 80; m_coinRectTwo->h = 80;
	//
	m_coinRectThree = new SDL_Rect();
	m_coinRectThree->x = 360; m_coinRectThree->y = 780;
	m_coinRectThree->w = 110; m_coinRectThree->h = 100;
}