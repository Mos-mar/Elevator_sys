#ifndef SERVICEREQUEST_HPP
#define SERVICEREQUEST_HPP
#include "request.hpp"

class ServiceRequest : public Request
{
public:
// Constructor for requests from outside the elevator
    ServiceRequest(RequestOrigin origin, int currentFloor, int destinationFloor)
        : Request(origin, currentFloor, destinationFloor)
    {
        elevatorType = ElevatorType::SERVICE;
    }
// Constructor for requests from inside the elevator
    ServiceRequest(RequestOrigin origin, int destinationFloor)
        : Request(origin, destinationFloor)
    {
        elevatorType = ElevatorType::SERVICE;
    }
};


#endif // serviceRequest_HPP