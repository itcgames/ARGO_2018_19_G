//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 15:59 12 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "Components.h"
#include "SDL.h"

//
class SpriteComponent : public Component
{
public:
	//
	SpriteComponent() = default;
	//
	/*SpirteComponent(const char* path)
	{

	}*/

	//
	void init() override
	{

	}

	//
	void update() override
	{

	}

	//
	void render() override
	{

	}


private:
	PositionComponent * m_position;
	SDL_Texture *m_texture;
	SDL_Rect m_srcRect, m_destRect;
};