#include "LicenceScreen.h"



LicenceScreen::LicenceScreen(SDL_Renderer* renderer)
{
	initialise(renderer);
}

LicenceScreen::~LicenceScreen()
{

}

void LicenceScreen::initialise(SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load("Resources/LicencePlaceholder.png");
	m_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	m_position = new SDL_Rect();

	m_position->x = 0;
	m_position->y = 0;
	m_position->w = 1920;
	m_position->h = 1080;
}

void LicenceScreen::update()
{
	std::cout << "updating licence" << std::endl;
}

void LicenceScreen::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, m_texture, NULL, m_position);
}
