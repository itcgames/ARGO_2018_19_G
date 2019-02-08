//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 15:20 4 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef EVENT_H
#define EVENT_H

class Event
{
public:
	//
	enum EventType
	{
		StopAnimation,
		StartRunningAnimation,
		StartRotateAnimation,
		PlayerRunning,
		PlayerJumped,
		PlayerHit,
		CoinCollected,
		Spawn
	};

	//
	Event(EventType type, void * tuple) : m_type(type)
	{
		m_tuple = tuple;
	}

	//
	~Event()
	{
		m_tuple = nullptr;
	}

	//
	void * m_tuple;
	EventType m_type;
};

#endif // !EVENT_H