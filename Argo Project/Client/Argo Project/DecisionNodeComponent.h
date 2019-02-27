#pragma once
#include "Component.h"
#include "Vector2.h"

//
class DecisionNodeComponent : public BaseComponent<DecisionNodeComponent>
{
public:
	DecisionNodeComponent(std::string type, int entityID) :
		BaseComponent<DecisionNodeComponent>(entityID),
		m_type(type)
	{

	}

	//
	std::string getType()
	{
		return m_type;
	}
	//

private:
	std::string m_type;

};