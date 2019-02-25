//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 10:05 25 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "SDL.h"

#include "Component.h"
#include "Vector2.h"

#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

//
class CollisionComponent : public BaseComponent<CollisionComponent>
{
public:
	CollisionComponent(SDL_Rect rect) :
		m_collisionBounds(rect)
	{

	}

	SDL_Rect getRect()
	{
		return m_collisionBounds;
	}

private:
	SDL_Rect m_collisionBounds;
};


#endif // !COLLISIONCOMPONENT_H