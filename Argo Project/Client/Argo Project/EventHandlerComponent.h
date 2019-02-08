//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 16:11 8 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef EVENTHANDLERCOMPONENT_H
#define EVENTHANDLERCOMPONENT_H

#include <map>
#include <vector>
#include "EventListenerComponent.h"
#include "Event.h"


class EventHandlerComponent : public BaseComponent<EventHandlerComponent>
{
public:
	//dictionary holding a list of litener objs for each event type
	std::map<
		Event::EventType,
		std::vector<EventListenerComponent*>* //pointer to vec of eventlisteners
	> m_listeners;

	//ddictionary of messages
	std::vector<Event * > m_events;
};


#endif // !EVENTHANDLERCOMPONENT_H
