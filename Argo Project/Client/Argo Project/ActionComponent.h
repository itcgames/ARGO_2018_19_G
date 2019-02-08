//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:12 8 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef ACTIONCOMPONENT_H
#define ACTIONCOMPONENT_H

#include "Component.h"
#include "Entity.h"

//
class ActionComponent : public BaseComponent<ActionComponent>
{
public:
	//
	ActionComponent() :
		m_playerEntity(),
		m_isActive(),
		m_isAIAssigned(),
		m_entityID()
	{

	}

	//
	~ActionComponent()
	{

	}

	enum ActionType
	{
		Running,
		Jumping,
		Hit
	};

	ActionType m_actionType;
	Entity * m_playerEntity;
	bool m_isActive, m_isAIAssigned;
	int m_entityID;

};

#endif // !ACTIONCOMPONENT_H