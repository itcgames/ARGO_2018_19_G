//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 14:54 18 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "Entity.h"

#ifndef BASESYSTEM_H
#define BASESYSTEM_H

//
class BaseSystem
{
public:
	void addEntity(Entity * entity)
	{
		m_entities.push_back(entity);
	}


protected:
	std::vector<Entity*> m_entities;
};

#endif // !BASESYSTEM_H

