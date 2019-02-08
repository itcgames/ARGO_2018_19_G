//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 11:21 4 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef PLAYER_H
#define PLAYER_H

#include "SDL.h"
#include "Entity.h"

#include <iostream>

class Player
{
public:
	Player();
	~Player();

	void init();
	void update();
	void render();


private:
	SDL_Rect m_postion;
	SDL_Texture* m_texture;
	SDL_Rect m_sourcePos;
};

#endif // !PLAYER_H
