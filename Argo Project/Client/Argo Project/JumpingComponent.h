//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 12:27 8 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef JUMPINGCOMPONENT_H
#define JUMPINGCOMPONENT_H

#include "Component.h"
#include "Entity.h"

//
class JumpingComponent : public BaseComponent<JumpingComponent>
{
public:
	//
	JumpingComponent()
	{

	}

	//
	~JumpingComponent()
	{

	}

	//
	void jumping()
	{
		if (m_isActive == true)
		{

		}
	}

	//
	Entity m_player;
	bool m_isActive;
	float m_jumpingSpeed;
};

#endif // !JUMPINGCOMPONENT_H
