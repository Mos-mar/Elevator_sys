#ifndef REQUEST_HPP
#define REQUEST_HPP
#include "enums.hpp"


class Request 
{
protected:
    RequestOrigin origin;
    State direction;
    int originFloor;
    int destinationFloor;
    ElevatorType elevatorType;

public:
// Constructor for requests from outside the elevator
    Request(RequestOrigin origin, int originFloor, int destinationFloor)
        : origin(origin), originFloor(originFloor), destinationFloor(destinationFloor), elevatorType(ElevatorType::PASSENGER)
    {

        if (originFloor > destinationFloor)
        {
            direction = State::GOING_DOWN;
        }
        else if (originFloor < destinationFloor)
        {
            direction = State::GOING_UP;
        }
        else
        {
            direction = State::IDLE;
        }
    }
// Constructor for requests from inside the elevator
    Request(RequestOrigin origin, int destinationFloor)
        : origin(origin), destinationFloor(destinationFloor), direction(State::IDLE), elevatorType(ElevatorType::PASSENGER)
    {}
    
    //Getters methods
    int getOriginFloor() const
    {
        return originFloor;
    }

    int getDestinationFloor() const
    {
        return destinationFloor;
    }

    RequestOrigin getOrigin() const
    {
        return origin;
    }

    State getDirection() const
    {
        return direction;
    }
};

#endif // resquest_HPP