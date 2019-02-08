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

#include "Component.h"

#include <unordered_map>

//
class Entity
{
public:
	//
	Entity()
	{
		m_id = id;
		id++;
	}
	//
	~Entity()
	{
		if (m_id > 0)
		{
			for (std::unordered_map<int, Component*>::iterator itr = m_map.begin(); itr != m_map.end(); itr++)
			{
				try
				{
					if (itr->first != 23)
						delete itr->second;
				}
				catch (...)
				{
					std::cout << "failed to delete, error: " << std::endl;
				}
			} // End for
		} // End if
	}

	//
	template <class T> T* getComponent(int type)
	{
		return static_cast<T*>(m_map[type]);
	};

	//
	void addComponent(Component * component, int type)
	{
		m_map[type] = component;
	}

	//
	static void resetID()
	{
		id = 1;
	}

	int m_id;

private:
	std::unordered_map<int, Component*> m_map;
	static int id;
};

#endif // !ENTITY_H
