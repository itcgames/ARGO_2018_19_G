//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 13:24 11 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "Player.h"

//
Player::Player(SDL_Renderer *renderer, int width, int height, int x, int y) :
	m_width(width),
	m_height(height),
	m_x(x),
	m_y(y)
{
	init(renderer);
}

//
Player::~Player()
{

}

//
void Player::init(SDL_Renderer *renderer)
{
	SDL_Surface* tempSurface = IMG_Load("Assets/Block2.png");
	m_texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	m_position = new SDL_Rect();


	m_position->x = m_x;
	m_position->y = m_y;
	m_position->w = m_width;
	m_position->h = m_height;
}

//
void Player::update(float deltaTime)
{

	/*if (Game::m_event.type == SDL_KEYDOWN)
	{
	switch (Game::m_event.key.keysym.sym)
	{
	case SDLK_SPACE:
	std::cout << "Space" << std::endl;
	break;
	default:
	break;
	}
	}

	if (Game::m_event.type == SDL_KEYUP)
	{
	switch (Game::m_event.key.keysym.sym)
	{
	case SDLK_SPACE:
	std::cout << "Space" << std::endl;
	break;
	default:
	break;
	}
	}

	pollEvents();*/
}

//
void Player::pollEvents(SDL_Event m_event)
{


	if (SDL_PollEvent(&m_event))
	{
		if (m_event.type == SDL_KEYDOWN)
		{
			switch (m_event.key.keysym.sym)
			{
			case SDLK_UP:
				std::cout << "Up" << std::endl;
				break;
			case SDLK_w:
				std::cout << "W" << std::endl;
				break;
			case SDLK_SPACE:
				std::cout << "Space" << std::endl;
				break;
			}
		}
	}
}

//
void Player::jump()
{

}

//
void Player::render(SDL_Renderer *renderer)
{
	//
	SDL_RenderCopy(renderer, m_texture, NULL, m_position);
}
