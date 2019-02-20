#pragma once
#include "Component.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Vector2.h"

class SpriteComponent : public BaseComponent<SpriteComponent>
{
public:
	SpriteComponent(SDL_Texture * texture, SDL_Rect * rect, int entityID):
		BaseComponent<SpriteComponent>(entityID),
		m_texture(texture), m_rect(rect), m_isActive(true)
	{

	}

	SDL_Rect* getRect()
	{
		return m_rect;
	}

	SDL_Texture* getTexture()
	{
		return m_texture;
	}

	void setRect(SDL_Rect* rect)
	{
		m_rect = rect;
	}

	void setTexture(SDL_Texture * texture)
	{
		m_texture = texture;
	}

	bool m_isActive;
	SDL_Texture * m_texture;
	SDL_Rect * m_rect;
	
};
