#pragma once

#include <vector>
#include "BaseSystem.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "SpriteComponent.h"

class NonPlayerMovementSystem : public BaseSystem
{
public:
	NonPlayerMovementSystem()
	{

	}

	void update(float deltatime)
	{
		for (int i = 0; i < m_entities.size(); i++)
		{

			m_entities[i]->getComponent<PositionComponent>(1)->setPosition(Vector2(m_entities[i]->getComponent<PositionComponent>(1)->getPosition().x - (m_speed * deltatime), m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y));

			SDL_Rect* newRect = new SDL_Rect();
			newRect->x = m_entities[i]->getComponent<PositionComponent>(1)->getPosition().x; newRect->y = m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y;
			newRect->w = m_entities[i]->getComponent<SpriteComponent>(2)->getRect()->w; newRect->h = m_entities[i]->getComponent<SpriteComponent>(2)->getRect()->h;

			m_entities[i]->getComponent<SpriteComponent>(2)->setRect(newRect);


			if (m_entities[i]->getComponent<PositionComponent>(1)->getPosition().x + m_entities[i]->getComponent<SpriteComponent>(2)->getRect()->w < 0)
			{
				//m_entities[i]->~Entity();
				m_entities[i] = nullptr;
				m_entities.erase(m_entities.begin() + i);
				i--;
			}
		}
	}
	

private:
	float m_speed = 10;
};