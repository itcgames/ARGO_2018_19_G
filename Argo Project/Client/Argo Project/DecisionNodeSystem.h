#pragma once
#include <vector>
#include "BaseSystem.h"
#include "Entity.h"
#include "PositionComponent.h"

class DecisionNodeSystem : public BaseSystem
{
public:
	DecisionNodeSystem()
	{

	}

	void update(float deltatime)
	{
		for (int i = 0; i < m_entities.size(); i++)
		{
			m_entities[i]->getComponent<PositionComponent>(1)->setPosition(Vector2(m_entities[i]->getComponent<PositionComponent>(1)->getPosition().x - (m_speed * deltatime), m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y));

			if (m_entities[i]->getComponent<PositionComponent>(1)->getPosition().x < 0)
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