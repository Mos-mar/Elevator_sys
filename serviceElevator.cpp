#include "serviceElevator.hpp"
#include "enums.hpp"

void ServiceElevator::operate(std::map<State, std::string>& StateMap)
{
    while (!serviceQueue.empty())
        {
            ServiceRequest *currRequest = serviceQueue.front();
            serviceQueue.pop_front();

            std::cout << std::endl
                      << "Currently at " << this->getCurrentFloor() << std::endl;
            try
            {
                std::cout << StateMap[currRequest->getDirection()];
                for (int i = 0; i < 3; i++)
                {
                    std::cout << ".";
                }
            }
            catch (const std::exception &e)
            {
                // Handle the exception here
                std::cerr << e.what() << std::endl;
            }
            this->setCurrentFloor(currRequest->getDestinationFloor());
            this->setState(currRequest->getDirection());
            std::cout << "Arrived at " << this->getCurrentFloor() << std::endl;
            this->openDoors();
            this->closeDoors();
        }
        this->setState(State::IDLE);
        std::cout << "All requests have been fulfilled, elevator is now " << StateMap[this->getState()] << std::endl;
}

void ServiceElevator::addRequestToQueue(ServiceRequest *request)
{            
 serviceQueue.push_back(request);   
}

void ServiceElevator::processEmergency(std::map<DoorState, std::string>& DoorStateMap){
    serviceQueue.clear();
    this->setCurrentFloor(1);
    this->setState(State::IDLE);
    this->openDoors();
    this->setEmergencyStatus(true);
    std::cout << "Queue cleared, current floor is " << this->getCurrentFloor() << ". Doors are " << DoorStateMap[this->getDoorState()] << std::endl;
}
