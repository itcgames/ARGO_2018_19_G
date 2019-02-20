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
	m_player = new Entity();

	m_pc = new PositionComponent(Vector2(50, 100), 1);

	m_player->addComponent<PositionComponent>(m_pc, 1);

	m_js.addEntity(m_player);
}

void PlayScreen::update(GameState* gameState)
{
	m_js.update();
}

void PlayScreen::render(SDL_Renderer *renderer)
{
	//SDL_RenderCopy(renderer, m_texture, NULL, m_position);
}
