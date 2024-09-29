#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "elevatorFactory.hpp"
#include "passengerElevator.hpp"
#include "serviceElevator.hpp"
#include <map>

class Controller
{
private:
    ElevatorFactory *factory;
    PassengerElevator *passengerElevator;
    ServiceElevator *serviceElevator;

public:
    Controller(ElevatorFactory *factory)
        : factory(factory)
    {
        passengerElevator = dynamic_cast<PassengerElevator *>(factory->createElevator(ElevatorType::PASSENGER));
        serviceElevator = dynamic_cast<ServiceElevator *>(factory->createElevator(ElevatorType::SERVICE));
    }

    void sendPassengerUpRequests(Request *request)
    {
        passengerElevator->addUpRequest(request);
    }

    void sendPassengerDownRequests(Request *request)
    {
        passengerElevator->addDownRequest(request);
    }

    void sendServiceRequest(ServiceRequest *request)
    {
        serviceElevator->addRequestToQueue(request);
    }

    void handlePassengerRequests()
    {
        passengerElevator->operate(std::map<State, std::string>& StateMap);
    }

    void handleServiceRequests()
    {
        serviceElevator->operate(std::map<State, std::string>& StateMap);
    }

    void handleEmergency()
    {
        passengerElevator->processEmergency(std::map<DoorState, std::string>& DoorStateMap);
        serviceElevator->processEmergency(std::map<DoorState, std::string>& DoorStateMap);
    }
};

#endif // controller_HPP