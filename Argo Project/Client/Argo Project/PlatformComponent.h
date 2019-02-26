//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 10:05 25 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "SDL.h"

#include "Component.h"
#include "Vector2.h"

#ifndef PLATFORMCOMPONENT_H
#define PLATFORMCOMPONENT_H

//
class PlatformComponent : public BaseComponent<PlatformComponent>
{
public:
	//
	PlatformComponent(SDL_Texture * texture, SDL_Rect * rect, int entityID) :
		BaseComponent<PlatformComponent>(entityID),
		m_texture(texture),
		m_rect(rect),
		m_isActive(true)
	{
		
	}

	//
	~PlatformComponent()
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
	bool m_isActive;
	SDL_Texture * m_texture;
	SDL_Rect * m_rect;
};

#endif // !PLATFORMCOMPONENT_H
