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

 std::map<State, std::string> StateMap = {
    {State::GOING_UP, "GOING_UP"},
    {State::GOING_DOWN, "GOING_DOWN"},
    {State::IDLE, "IDLE"}
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

 std::map<DoorState, std::string> DoorStateMap = {
    {DoorState::OPEN, "OPEN"},
    {DoorState::CLOSED, "CLOSED"}
};


#endif // ENUMS_HPP