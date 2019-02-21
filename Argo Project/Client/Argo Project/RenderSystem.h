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
#include "PositionComponent.h"

class RenderSystem : public BaseSystem
{
public:
	//
	RenderSystem()
	{

	}

	//
	~RenderSystem()
	{

	}

	//
	void update()
	{

	}

	//
	void render(SDL_Renderer *renderer)
	{
		std::cout << "Render" << std::endl;

		for (int i = 0; i < m_entities.size(); i++)
		{
			SpriteComponent* sprite = m_entities[i]->getComponent<SpriteComponent>(2);

			SDL_RenderCopy(renderer, sprite->getTexture(), NULL, sprite->getRect());
		}
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
