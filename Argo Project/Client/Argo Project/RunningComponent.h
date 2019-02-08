//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 12:27 8 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef RUNNINGCOMPONENT_H
#define RUNNINGCOMPONENT_H

#include "Component.h"
#include "Entity.h"

//
class RunningComponent : public BaseComponent<RunningComponent>
{
public:
	//
	RunningComponent()
	{

	}

	//
	~RunningComponent()
	{

	}

	//
	void movePlayer() 
	{
		if (m_isActive == true)
		{

		}
	}

	//
	Entity m_player;
	bool m_isActive;
	float m_maxSpeed, m_speed;
};

#endif // !RUNNINGCOMPONENT_H
