//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:01 12 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef ECS_H
#define ECS_H

#include "Entity.h"
#include "Component.h"
#include "PositionComponent.h"
#include "RenderSystem.h"
#include "JumpingSystem.h"


/*class Component;
class Entity;

using ComponentID = std::size_t;

//
inline ComponentID getComponentID()
{
	static ComponentID m_lastID = 0;
	return m_lastID++;
}

//
template <typename T> inline ComponentID getComponentID() noexcept
{
	static ComponentID m_typeID = getComponentID();
	return m_typeID();
}

//
constexpr std::size_t m_maxComponents = 32;

//
using ComponentBitSet = std::bitset<m_maxComponents>;
using ComponentArray = std::array<Component*, m_maxComponents>;

//
/*class Component
{
public:
	Entity * entity;

	//
	virtual void init()
	{

	}
	//
	virtual void update()
	{

	}

	//
	virtual void render()
	{

	}
	
	virtual ~Component();

};

//
class Entity
{
public:

	//
	void update()
	{
		//
		for (auto& c : m_components)
		{
			c->update();
		}
		//
		for (auto& c : m_components)
		{
			c->render();
		}

	}

	//
	void render()
	{

	}

	//
	bool isActive() const
	{
		return m_active;
	}

	//
	void destroy()
	{
		m_active = false;
	}

	//
	template <typename T> bool hasComponent() const
	{
		return componentBitSet[getComponentID<T>];
	}

	//
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		/*T* c(new T(std::forward<TArgs>(mArgs)...);
		c->entity = this;
		std::unique_ptr<Component> uniquePtr
		{
			c
		};
		m_components.emplace_back(std::move(uniquePtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

private:
	bool m_active = true;
	std::vector<std::unique_ptr<Component>> m_components;

	ComponentArray m_componentArray;
	ComponentBitSet m_componentBitSet;

	//
	template<typename T> T& getComponenet() const
	{
		/*auto pointer(m_componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(pointer);
	}
};

//
class Manager
{
public:
	//
	void update()
	{
		for (auto& e : m_entities)
		{
			e->update();
		}
	}

	//
	void render()
	{
		for (auto& e : m_entities)
		{
			e->render();
		}
	}

	//
	void refresh()
	{
		m_entities.erase(std::remove_if(std::begin(m_entities), std::end(m_entities),
			[](const std::unique_ptr<Entity> &mentity)
		{
			return !mentity->isActive();
		}),
			std::end(m_entities));
	}

	//
	Entity& addEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uniquePtr { e };
		m_entities.emplace_back(std::move(uniquePtr));
		return *e;
	}

private:
	std::vector<std::unique_ptr<Entity>> m_entities;
};*/

#endif //! ECS_H