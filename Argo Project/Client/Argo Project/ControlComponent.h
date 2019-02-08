//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 15:20 8 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Component.h"

//
class ControlComponent : public BaseComponent<ControlComponent>
{
public:
	ControlComponent(int entityID, int id) :
		BaseComponent(entityID),
		m_keyID(id),
		m_shouldTakeMovementInput(true)
	{

	}

	enum Keys
	{
		Space,
		W,
		Uparrow
	};

	int m_keyID;
	bool m_shouldTakeMovementInput;
};

#endif // !INPUTHANDLER_H
