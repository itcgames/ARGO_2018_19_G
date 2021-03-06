//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 15:53 7 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef REDNERSYSTEM_H
#define REDNERSYSTEM_H

#include <vector>

#include "BaseSystem.h"
#include "Entity.h"
#include "ECS.h"

class RenderSystem : public BaseSystem
{
public:
	//
	RenderSystem()
	{

	}

	//
	void render(SDL_Renderer *renderer)
	{
		for (int i = 0; i < m_entities.size(); i++)
		{
			if (m_entities[i]->getComponent<PositionComponent>(1)->getPosition().x + m_entities[i]->getComponent<SpriteComponent>(2)->getRect()->w < 0)
			{
				m_entities[i] = nullptr;
				m_entities.erase(m_entities.begin() + i);
				i--;
			}
			else
			{
				SpriteComponent* sprite = m_entities[i]->getComponent<SpriteComponent>(2);

				SDL_RenderCopy(renderer, sprite->getTexture(), NULL, sprite->getRect());
			}
		}
	}

	//
	void renderImage(SDL_Renderer* renderer, SpriteComponent* spriteComponent)
	{
		SDL_RenderCopy(renderer, spriteComponent->getTexture(), NULL, spriteComponent->getRect());
	}

private:
	//
	SDL_Rect * m_position;
	SDL_Texture* m_texture;
	//
	int m_width, m_height;
	int m_x, m_y;
};

#endif // !RENDERSYSTEM_H
