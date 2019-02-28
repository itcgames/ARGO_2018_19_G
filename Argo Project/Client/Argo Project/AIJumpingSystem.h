#pragma once
#include <vector>

#include "BaseSystem.h" 
#include "Entity.h"
#include "PositionComponent.h"

//
class AIJumpingSystem :public BaseSystem
{
public:
	//
	AIJumpingSystem()
	{

	}

	//
	~AIJumpingSystem()
	{

	}


	//
	void update(float deltaTime)
	{
		for (int i = 0; i < m_entities.size(); i++)
		{

			if (m_jump == true && m_jumped == false)
			{
				m_velY = 50;
				m_newY = 0;
				m_jump = true;
				m_grounded = false;
				m_up = true;
				m_down = false;
				m_jumped = true;
				m_maxHeight = m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y - 400;
			}

			if (m_jump == true)
			{
				//
				if (m_up == true)
				{
					m_newY = m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y - (m_speed * deltaTime);

					//
					if (m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y <= m_maxHeight)
					{
						m_up = false;
						m_down = true;
					}
				}

				//
				else if (m_down == true)
				{
					m_newY = m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y + (m_speed * deltaTime);
				}

				m_entities[i]->getComponent<PositionComponent>(1)->setPosition(Vector2(m_entities[i]->getComponent<PositionComponent>(1)->getPosition().x, m_newY));
			}
		}
	}

	void setGrounded(bool grounded)
	{
		m_grounded = grounded;
		//
		if (m_grounded == true)
		{
			m_jumped = false;
			m_jump = false;
			m_down = false;
		}

		//
		if (m_grounded == false)
		{
			m_jumped = true;
			m_jump = true;
			m_down = true;
		}
	}

	bool getJump()
	{
		return m_jump;
	}

	void setJump(bool jump)
	{
		m_jump = jump;
	}

private:
	SDL_Event m_event;
	SDL_Keycode m_key;

	float m_velY, m_newY;
	float m_gravity = -3.5;
	float m_maxHeight = 0.0f;
	float m_speed = 20.0f;

	bool m_grounded = true, m_jump = false, m_jumped = false, m_up = false, m_down = false;
};