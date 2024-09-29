#ifndef PASSENGERELEVATOR_HPP
#define PASSENGERELEVATOR_HPP

#include "elevator.hpp"
#include "request.hpp"
#include <queue>
#include <functional>
class PassengerElevator : public Elevator
{
private:
    std::priority_queue<Request *, std::vector<Request *>, std::function<bool(Request *, Request *)>> passengerUpQueue;
    std::priority_queue<Request *, std::vector<Request *>, std::function<bool(Request *, Request *)>> passengerDownQueue;

public:
PassengerElevator(int currentFloor, bool emergencyStatus)
        : Elevator(currentFloor, emergencyStatus),
          passengerUpQueue([](Request *a, Request *b)
                           { return a->getDestinationFloor() > b->getDestinationFloor(); }),
          passengerDownQueue([](Request *a, Request *b)
                             { return a->getDestinationFloor() < b->getDestinationFloor(); })
    {
    }
void operate(std::map<State, std::string>& StateMap) override;
void processEmergency(std::map<DoorState, std::string>& DoorStateMap) override;
void addDownRequest(Request *request);
void addUpRequest(Request *request);
void processUpRequests();
void processDownRequests();
void processRequests();
};
#endif // passengerElevator_HPP