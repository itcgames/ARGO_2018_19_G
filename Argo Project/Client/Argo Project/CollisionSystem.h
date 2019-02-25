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
	bool platformCollisions(Entity* player, Entity* object)
	{
		bool collide = false;
		//
		if (SDL_HasIntersection(player->getComponent<SpriteComponent>(2)->getRect(), object->getComponent<PlatformComponent>(4)->getRect()) == true)
		{
			std::cout << "Collision!" << std::endl;
			collide = true;
		}

		return collide;
	}

};

#endif // !COLLISIONSYSTEM_H
