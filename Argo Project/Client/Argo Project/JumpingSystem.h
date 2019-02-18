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
			
			std::cout << m_entities[i]->getComponent<PositionComponent>(1)->getPosition().x << std::endl;
			std::cout << m_entities[i]->getComponent<PositionComponent>(1)->getPosition().y << std::endl;
			
		}
	}

private:
};

#endif // !JUMPINGVELOCITY_H