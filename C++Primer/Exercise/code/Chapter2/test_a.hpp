#ifndef _EVENT_DISPATCHER_HPP_
#define _EVENT_DISPATCHER_HPP_

#include <map>

class EventDispatcher
{
    public:
        static EventDispatcher* Get();
        static EventDispatcher& Get(unsigned dispatcherId);
        void Setup(unsigned dispatcherId);
        static void Print();

    private:
        static std::map<int, EventDispatcher>* m_eventDispatchers;
};

#endif
