#pragma once

#include <iostream>

class Game
{
public:
	Game();

	void init();
	void run();
	

private:
	void update();
	void render();
};