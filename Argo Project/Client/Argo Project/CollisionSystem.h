//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 10:05 25 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include <vector>

#include "BaseSystem.h"
#include "Entity.h"
#include "ECS.h"

#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

class CollisionSystem : public BaseSystem
{
public:
	bool intersectRect(Entity* player, Entity* object)
	{
		bool collide = false;
		//
		if (SDL_HasIntersection(player->getComponent<SpriteComponent>(2)->getRect(), object->getComponent<SpriteComponent>(2)->getRect()) == true)
		{
			//std::cout << "Collide" << std::endl;
			collide = true;
		}

		return collide;
	}

	bool decisionPointIntersect(Entity* ai, Entity* node)
	{
		bool collide = false;
		//

		SDL_Point* point = new SDL_Point();
		point->x = node->getComponent<PositionComponent>(1)->getPosition().x; point->y = node->getComponent<PositionComponent>(1)->getPosition().y;

		if (SDL_PointInRect(point, ai->getComponent<SpriteComponent>(2)->getRect()) == true)
		{
			collide = true;
		}

		return collide;
	}

	//
	bool platformCollisionSide(Entity* player, Entity* object)
	{
		bool collide = false;
		//
		if ((player->getComponent<SpriteComponent>(2)->getRect()->x <= object->getComponent<SpriteComponent>(2)->getRect()->w ||
			player->getComponent<SpriteComponent>(2)->getRect()->w >= object->getComponent<SpriteComponent>(2)->getRect()->x) &&
			(player->getComponent<SpriteComponent>(2)->getRect()->y > object->getComponent<SpriteComponent>(2)->getRect()->y &&
				player->getComponent<SpriteComponent>(2)->getRect()->y < object->getComponent<SpriteComponent>(2)->getRect()->h) ||
				(player->getComponent<SpriteComponent>(2)->getRect()->h >= object->getComponent<SpriteComponent>(2)->getRect()->y &&
					player->getComponent<SpriteComponent>(2)->getRect()->h < object->getComponent<SpriteComponent>(2)->getRect()->h))
		{
			collide = true;

			std::cout << "Side Collision" << std::endl;
		}

		return collide;
	}


	//
	bool platformCollisionTopBottom(Entity* player, Entity* object)
	{
		bool collide = false;
		//
		if ((player->getComponent<SpriteComponent>(2)->getRect()->y <= object->getComponent<SpriteComponent>(2)->getRect()->h ||
			player->getComponent<SpriteComponent>(2)->getRect()->h >= object->getComponent<SpriteComponent>(2)->getRect()->y) &&
			(player->getComponent<SpriteComponent>(2)->getRect()->x > object->getComponent<SpriteComponent>(2)->getRect()->x &&
				player->getComponent<SpriteComponent>(2)->getRect()->x < object->getComponent<SpriteComponent>(2)->getRect()->w) ||
				(player->getComponent<SpriteComponent>(2)->getRect()->w >= object->getComponent<SpriteComponent>(2)->getRect()->x &&
					player->getComponent<SpriteComponent>(2)->getRect()->w < object->getComponent<SpriteComponent>(2)->getRect()->w))
		{
			collide = true;

			//std::cout << "Topbottom Collision" << std::endl;
		}

		return collide;
	}

	bool collision(Entity* player, Entity* object)
	{

	}

};

#endif // !COLLISIONSYSTEM_H
