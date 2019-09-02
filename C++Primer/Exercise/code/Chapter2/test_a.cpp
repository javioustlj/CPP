#include <iostream>
#include "test_a.hpp"

std::map<int, EventDispatcher>* EventDispatcher::m_eventDispatchers = NULL;

EventDispatcher& EventDispatcher::Get(unsigned dispatcherId)
{
    if(NULL == m_eventDispatchers)
        m_eventDispatchers = new std::map<int, EventDispatcher>();
    return (*m_eventDispatchers)[dispatcherId];
}

EventDispatcher* EventDispatcher::Get()
{
    return new EventDispatcher();
}

void EventDispatcher::Setup(unsigned dispatcherId)
{
    std::cout << "setup" << dispatcherId << std::endl;
}

void EventDispatcher::Print()
{
    std::cout << "m_eventDispatchers:\n";

    for (const auto &a : *m_eventDispatchers)
        std::cout << a.first << '\n';

    std::cout << std::endl;
}
