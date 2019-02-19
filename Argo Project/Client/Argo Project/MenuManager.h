#pragma once

#ifndef MENUMANAGER
#define MENUMANAGER


enum class GameState
{
	Licence,
	Splash,
	MainMenu,
	Play,
	Options,
	Help,
	Credits
};

class MenuManager
{
public:
	MenuManager();
	~MenuManager();

private:

};

#endif // !MENUMANAGER

