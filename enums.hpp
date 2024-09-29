#ifndef ENUMS_HPP
#define ENUMS_HPP
#include <iostream>
#include <thread>
#include <queue>
#include <list>
#include <map>

enum class State
{
    GOING_UP,
    GOING_DOWN,
    IDLE
};

enum class ElevatorType
{
    PASSENGER,
    SERVICE
};

enum class RequestOrigin
{
    OUTSIDE,
    INSIDE
};

enum class DoorState
{
    OPEN,
    CLOSED
};

#endif // ENUMS_HPP