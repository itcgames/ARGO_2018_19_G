//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:21 4 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef ENTITY_H
#define ENTITY_H

#include "ECS.h"
#include "Component.h"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

//
class Entity
{
public:
	//
	Entity()
	{

	}

	//
	template <class T>
	T* getComponent(int type)
	{
		return static_cast<T*>(m_component[type]);
	};

	//
	template <class T>
	void addComponent(Component * component, int type)
	{
		m_component[type] = component;
	};

private:
	std::unordered_map<int, Component*> m_component;
	//std::vector<Component> m_components;
	//std::string m_componentName;
	int m_ID;
};

#endif // !ENTITY_H
