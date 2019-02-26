#pragma once
#include "SDL.h"
class LTimer
{
public:
	LTimer();

	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTicks();

	bool isStarted();
	bool isPaused();

private:

	Uint32 m_startTicks;
	Uint32 m_pausedTicks;

	bool m_paused;
	bool m_started;
};