#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP
#include "enums.hpp"

class Elevator {
    protected:
    int currentFloor;
    State state;
    bool emergencyStatus;
    DoorState doorState;

public:
    Elevator(int currentFloor, bool emergencyStatus)
    : currentFloor(currentFloor), state(State::IDLE), emergencyStatus(emergencyStatus), doorState(DoorState::CLOSED)
    {
    }
    void openDoors()
    {
        doorState = DoorState::OPEN;
        std::cout << "Doors are OPEN on floor " << currentFloor << std::endl;
    }

    void closeDoors()
    {
        doorState = DoorState::CLOSED;
        std::cout << "Doors are CLOSED" << std::endl;
    }

    virtual void operate() = 0; // Pure virtual function

    virtual void processEmergency() = 0;

    int getCurrentFloor() const
    {
        return currentFloor;
    }

    State getState() const
    {
        return state;
    }

    void setState(State state)
    {
        this->state = state;
    }

    void setCurrentFloor(int currentFloor)
    {
        this->currentFloor = currentFloor;
    }

    DoorState getDoorState() const
    {
        return doorState;
    }

    void setEmergencyStatus(bool status)
    {
        emergencyStatus = status;
    }

    virtual ~Elevator() {}
};
#endif // elevator_HPP