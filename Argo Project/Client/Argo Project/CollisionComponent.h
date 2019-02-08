//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 12:27 8 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include "Component.h"
#include "Entity.h"

//
class CollisionComponent : public BaseComponent<CollisionComponent>
{
public:
	//
	CollisionComponent()
	{

	}

	//
	~CollisionComponent()
	{

	}



	//
	Entity m_player;
	bool m_isActive;
};

#endif // !COLLISIONCOMPONENT_H