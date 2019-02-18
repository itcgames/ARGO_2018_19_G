//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 9:50 7 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "Component.h"
#include "Vector2.h"

#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

//
class PositionComponent : public BaseComponent<PositionComponent>
{
public:
	PositionComponent(Vector2 position, int entityID) :
		BaseComponent<PositionComponent>(entityID),
		m_position(position)
	{

	}

	//
	Vector2 getPosition()
	{
		return m_position;
	}
	//
	void setPosition(Vector2 position)
	{
		this->m_position = position;
	}

private:
	Vector2 m_position;

};

#endif // !POSITIONCOMPONENT_H