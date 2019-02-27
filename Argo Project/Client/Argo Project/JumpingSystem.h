//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 15:53 7 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef JUMPINGVELOCITY_H
#define JUMPINGVELOCITY_H

#include <vector>

#include "BaseSystem.h" 
#include "Entity.h"
#include "PositionComponent.h"

//
class JumpingSystem :public BaseSystem
{
public:
	//
	JumpingSystem()
	{

	}

	//
	~JumpingSystem()
	{

	}


	//
	void update(float deltaTime)
	{
		for (int i = 0; i < m_entities.size(); i++)
		{
			while (SDL_PollEvent(&m_event))
			{
				//
				if (m_event.type == SDL_KEYDOWN)
				{
					switch (m_event.key.keysym.sym)
					{
					case SDLK_UP:
						//
						if (m_jump == false && m_grounded == true)
						{
							m_velY = 50;
							m_newY = 0;
							m_jump = true;
							m_grounded = false;
							m_up = true;
							m_down = false;
							m_maxHeight = m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y - 400;
						}

						break;
					case SDLK_w:
						//
						if (m_jump == false && m_grounded == true)
						{
							m_velY = 50;
							m_newY = 0;
							m_jump = true;
							m_grounded = false;
							m_up = true;
							m_down = false;
							m_maxHeight = m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y - 400;
						}

						break;
					case SDLK_SPACE:
						//
						if (m_jump == false && m_grounded == true)
						{
							m_velY = 50;
							m_newY = 0;
							m_jump = true;
							m_grounded = false;
							m_up = true;
							m_down = false;
							m_maxHeight = m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y - 400;
						}
						break;
					}
				}
			}

			if (m_jump == true)
			{
				//m_position.y + ((m_velocity.y * deltaTime.asSeconds()) + (0.5 * m_gravity.y) * (deltaTime.asSeconds() * deltaTime.asSeconds()))
				//m_velY -= m_gravity * deltaTime;
				//m_newY -= m_velY;
				//m_newY += ((m_velY * deltaTime) + ((0.5 * m_gravity) * (deltaTime * deltaTime)));

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
			m_jump = false;
			m_down = false;
		}

		//
		if (m_grounded == false)
		{
			m_jump = true;
			m_down = true;
		}
	}

	bool getJump()
	{
		return m_jump;
	}

private:
	SDL_Event m_event;
	SDL_Keycode m_key;

	float m_velY, m_newY;
	float m_gravity = -3.5;
	float m_maxHeight = 0.0f;
	float m_speed = 20.0f;

	bool m_grounded = true, m_jump = false, m_up = false, m_down = false;
};

#endif // !JUMPINGVELOCITY_H