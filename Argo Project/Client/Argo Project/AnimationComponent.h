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
enum AnimationType
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
		m_animationtype = AnimationType::Running;
	}

	//
	void setAnimated(bool animated)
	{
		m_animated = animated;
	}

	void setFrames(int frames)
	{
		m_frames = frames;
	}

	void setSpeed(int speed)
	{
		m_speed = speed;
	}

	void setAnimationType(AnimationType animationType)
	{
		m_animationtype = animationType;
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

	AnimationType getAnimationType()
	{
		return m_animationtype;
	}

private:
	bool m_animated; 
	int m_frames;
	int m_speed;

	AnimationType m_animationtype;
};

#endif // !ANIMATIONCOMPONENT_H
