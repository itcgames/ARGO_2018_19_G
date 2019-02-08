//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:30 7 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "Component.h"

#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

class HealthComponent : public BaseComponent <HealthComponent>
{
public:
	//
	HealthComponent(int health) : m_health(health)
	{

	}

	//
	~HealthComponent()
	{

	}

	//
	int getHealth()
	{
		return m_health;
	}
	//
	void setHealth(int health)
	{
		this->m_health = health;
	}

private:
	int m_health;
};

#endif // !HEALTHCOMPONENT_H
