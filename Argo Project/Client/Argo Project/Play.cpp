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
	m_sc = new SpriteComponent(m_playerTxt, m_playerRect, 1);

	m_player->addComponent<PositionComponent>(m_pc, 1);
	m_player->addComponent<SpriteComponent>(m_sc, 1);
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

	m_rs.renderImage(renderer, m_player->getComponent<SpriteComponent>(1));
}


void PlayScreen::initSprites(SDL_Renderer *renderer)
{
	SDL_Surface* backgroundSurface = IMG_Load("ASSETS/8.png");
	SDL_Surface* playerSurface = IMG_Load("resources/Player.png");

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