#ifndef SERVICEELEVATOR_HPP
#define SERVICEELEVATOR_HPP
#include <list>
#include "elevator.hpp"
#include "serviceRequest.hpp"

class ServiceElevator : public Elevator 
{
private:
    std::list<ServiceRequest *> serviceQueue;
public:
ServiceElevator(int currentFloor, bool emergencyStatus)
        : Elevator(currentFloor, emergencyStatus) {}

        void operate(std::map<State, std::string>& StateMap) override;
        void addRequestToQueue(ServiceRequest *request);
        void processEmergency(std::map<DoorState, std::string>& DoorStateMap) override;
    
    
        

};

#endif // serviceElevator_HPP