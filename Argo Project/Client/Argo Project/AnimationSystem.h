//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 15:53 7 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef ANIMATIONSYSTEM_H
#define ANIMATIONSYSTEM_H

#include <vector>

#include "BaseSystem.h" 
#include "Entity.h"
#include "ECS.h"

//
class AnimationSystem :public BaseSystem
{
public:
	void animationPlayer(Entity* player)
	{
		if (player->getComponent<AnimationComponent>(5)->getAnimated() == true)
		{

		}
	}

private:


};

#endif // !ANIMATIONSYSTEM_H