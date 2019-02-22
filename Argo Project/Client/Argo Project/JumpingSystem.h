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
	void update()
	{
		for (int i = 0; i < m_entities.size(); i++)
		{
			while (SDL_PollEvent(&m_event))
			{
				//
				if (m_event.type == SDL_KEYDOWN)
				{
					//std::cout << "Any" << std::endl;

					switch (m_event.key.keysym.sym)
					{
					case SDLK_UP:
						std::cout << "Up" << std::endl;
						//
						if (m_jump == false && m_grounded == true)
						{
							m_velY = -16;
							m_jump = true;
							m_grounded = false;
						}

						break;
					case SDLK_w:
						std::cout << "W" << std::endl;
						//
						if (m_jump == false && m_grounded == true)
						{
							m_velY = -16;
							m_jump = true;
							m_grounded = false;
						}

						break;
					case SDLK_SPACE:
						std::cout << "Space" << std::endl;
						//
						if (m_jump == false && m_grounded == true)
						{
							m_velY = -16;
							m_jump = true;
							m_grounded = false;
						}

						break;
					}
				}
			}

			if (m_jump == true)
			{
				m_velY += m_gravity;
				m_newY += m_velY;
				m_entities[i]->getComponent<PositionComponent>(1)->setPosition(Vector2(m_entities[i]->getComponent<PositionComponent>(1)->getPosition().x, m_newY));
				std::cout << m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y << std::endl;
			}


			//
			if (m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y >= 780)
			{
				m_entities[i]->getComponent<PositionComponent>(1)->setPosition(Vector2(m_entities[i]->getComponent<PositionComponent>(1)->getPosition().x, 780));
				m_jump = false;
				m_grounded = true;
			}

		}
	}

private:
	SDL_Event m_event;
	SDL_Keycode m_key;

	float m_velY, m_newY;
	float m_gravity = 0.7;

	bool m_grounded = true, m_jump = false;
};

#endif // !JUMPINGVELOCITY_H
