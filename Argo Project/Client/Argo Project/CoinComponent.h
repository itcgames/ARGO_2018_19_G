//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:21 23 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "SDL.h"

#include "Component.h"
#include "Vector2.h"

#ifndef COINCOMPONENT_H
#define COINCOMPONENT_H

//
class CoinComponent : public BaseComponent<CoinComponent>
{
public:
	CoinComponent(SDL_Texture * texture, SDL_Rect * rect,
		int entityID, int coinType) :
		BaseComponent<CoinComponent>(entityID),
		m_texture(texture),
		m_rect(rect),
		m_coinType(coinType),
		m_isActive(true)
	{
		if (m_coinType != 1 ||
			m_coinType != 2 ||
			m_coinType != 3)
		{
			m_coinType = 1;
		}
	}

	~CoinComponent()
	{

	}

	//
	bool getIsActive()
	{
		return m_isActive;
	}

	//
	void seActive(bool active)
	{
		m_isActive = active;
	}

private:
	int m_coinType;
	bool m_isActive;
	SDL_Texture * m_texture;
	SDL_Rect * m_rect;

};

#endif // !COINCOMPONENT_H
