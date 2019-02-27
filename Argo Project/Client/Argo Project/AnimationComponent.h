//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 10:05 25 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#include "Component.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Vector2.h"

#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

//
enum AnmationType
{
	Climbing,
	Running,
	Jumping
};

//
class AnimationComponent : public BaseComponent<AnimationComponent>
{
public:
	AnimationComponent(bool animated, int frames, int speed, int entityID) :
		BaseComponent<AnimationComponent>(entityID),
		m_animated(animated),
		m_frames(frames),
		m_speed(speed)
	{

	}

	//
	void setAnimated(bool animated)
	{
		
	}

	void setFrames(int frames)
	{
		
	}

	void setSpeed(int speed)
	{
		
	}

	//
	bool getAnimated()
	{
		return m_animated;
	}

	int getFrames()
	{
		return m_frames;
	}

	int getSpeed()
	{
		return m_speed;
	}

private:
	bool m_animated; 
	int m_frames;
	int m_speed;
};

#endif // !ANIMATIONCOMPONENT_H
