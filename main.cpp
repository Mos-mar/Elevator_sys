
#include "controller.hpp"
std::map<DoorState, std::string> DoorStateMap = {
    {DoorState::OPEN, "OPEN"},
    {DoorState::CLOSED, "CLOSED"}
 };

std::map<State, std::string> StateMap = {
    {State::GOING_UP, "GOING_UP"},
    {State::GOING_DOWN, "GOING_DOWN"},
    {State::IDLE, "IDLE"}
};

int main()
{

    
    ElevatorFactory factory;
    Controller controller(&factory);

    controller.sendPassengerUpRequests(new Request(RequestOrigin::OUTSIDE, 1, 5));
    controller.sendPassengerDownRequests(new Request(RequestOrigin::OUTSIDE, 4, 2));
    controller.sendPassengerUpRequests(new Request(RequestOrigin::OUTSIDE, 3, 6));
    controller.handlePassengerRequests(StateMap);

    controller.sendPassengerUpRequests(new Request(RequestOrigin::OUTSIDE, 1, 9));
    controller.sendPassengerDownRequests(new Request(RequestOrigin::INSIDE, 5));
    controller.sendPassengerUpRequests(new Request(RequestOrigin::OUTSIDE, 4, 12));
    controller.sendPassengerDownRequests(new Request(RequestOrigin::OUTSIDE, 10, 2));
    controller.handlePassengerRequests(StateMap);

    std::cout << "Now processing service requests" << std::endl;

    controller.sendServiceRequest(new ServiceRequest(RequestOrigin::INSIDE, 13));
    controller.sendServiceRequest(new ServiceRequest(RequestOrigin::OUTSIDE, 13, 2));
    controller.sendServiceRequest(new ServiceRequest(RequestOrigin::INSIDE, 13, 15));

    controller.handleServiceRequests(StateMap);

    return 0;
}


