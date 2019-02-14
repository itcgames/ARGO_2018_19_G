#pragma once
#include "LicenceScreen.h"
#include "SplashScreen.h"
#include "MainMenuScene.h"
#include "OptionsScreen.h"
#include "CreditsScreen.h"
#include "HelpScreen.h"
#include <map>

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

