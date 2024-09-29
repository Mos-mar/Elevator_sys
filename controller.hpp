#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "elevatorFactory.hpp"
#include "passengerElevator.hpp"
#include "serviceElevator.hpp"

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
        passengerElevator->operate();
    }

    void handleServiceRequests()
    {
        serviceElevator->operate();
    }

    void handleEmergency()
    {
        passengerElevator->processEmergency();
        serviceElevator->processEmergency();
    }
};

#endif // controller_HPP