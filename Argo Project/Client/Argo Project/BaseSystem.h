//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 14:35 8 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef BASESYSTEM_H
#define BASESYSTEM_H

#include "Entity.h"

#include <vector>

//
class BaseSystem
{
	void addEntity(Entity * entity)
	{
		m_entities.push_back(entity);
	}
protected:
	std::vector<Entity *> m_entities;
};

#endif // !BASESYSTEM_H
