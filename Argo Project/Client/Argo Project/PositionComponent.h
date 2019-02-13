//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 9:50 7 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "ECS.h"
#include "Vector2.h"

#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

//
class PositionComponent : public Component
{
public:
	PositionComponent(Vector2 position) :
		m_position(position)
	{

	}

	~PositionComponent()
	{

	}

	//
	Vector2 getPosition()
	{
		return m_position;
	}
	//
	void setHealth(Vector2 position)
	{
		this->m_position = position;
	}

private:
	Vector2 m_position;

};

#endif // !POSITIONCOMPONENT_H