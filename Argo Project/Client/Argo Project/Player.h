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
#include "SDL_image.h"


#include <iostream>

class Player
{
public:
	Player(SDL_Renderer *renderer, int width, int height, int x, int y);
	~Player();

	void init(SDL_Renderer *renderer);
	void update(float deltaTime);
	
	void render(SDL_Renderer *renderer);

	void pollEvents(SDL_Event m_event);

	

private:
	
	void jump();

	bool m_jumping;

	SDL_Rect *m_position;
	SDL_Texture* m_texture;

	//
	int m_width, m_height;
	int m_x, m_y;
};

#include "Game.h"

#endif // !PLAYER_H
