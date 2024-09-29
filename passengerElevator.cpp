#include "passengerElevator.hpp"
#include "enums.hpp"

void PassengerElevator::operate(std::map<State, std::string>& StateMap)
{
    while (!passengerUpQueue.empty() || !passengerDownQueue.empty())
        {
            processRequests();
        }
        this->setState(State::IDLE);
        std::cout << "All requests have been fulfilled, elevator is now " << StateMap[this->getState()] << std::endl;
}

void PassengerElevator::processEmergency(std::map<DoorState, std::string>& DoorStateMap)
{
        while (!passengerUpQueue.empty())
            passengerUpQueue.pop();
        while (!passengerDownQueue.empty())
            passengerDownQueue.pop();

        this->setCurrentFloor(1);
        this->setState(State::IDLE);
        this->openDoors();
        this->setEmergencyStatus(true);
        std::cout << "Queues cleared, current floor is " << this->getCurrentFloor() << ". Doors are " << DoorStateMap[this->getDoorState()] << std::endl;
}

void PassengerElevator::addDownRequest(Request *request)
{
     if (request->getOrigin() == RequestOrigin::OUTSIDE)
        {
            Request *pickUpRequest = new Request(request->getOrigin(), request->getOriginFloor(), request->getOriginFloor());
            passengerDownQueue.push(pickUpRequest);
        }
        passengerDownQueue.push(request);
}

void PassengerElevator::addUpRequest(Request *request)
{
        if (request->getOrigin() == RequestOrigin::OUTSIDE)
        {
            Request *pickUpRequest = new Request(request->getOrigin(), request->getOriginFloor(), request->getOriginFloor());
            passengerUpQueue.push(pickUpRequest);
        }
        passengerUpQueue.push(request);
}

void PassengerElevator::processUpRequests()
{
    while (!passengerUpQueue.empty())
        {
            Request *upRequest = passengerUpQueue.top();
            passengerUpQueue.pop();

            if (this->getCurrentFloor() == upRequest->getDestinationFloor())
            {
                std::cout << "Currently on floor " << this->getCurrentFloor() << ". No movement as destination is the same." << std::endl;
                continue;
            }
            std::cout << "The current floor is " << this->getCurrentFloor() << ". Next stop: " << upRequest->getDestinationFloor() << std::endl;

            std::cout << "Moving ";
            for (int i = 0; i < 3; i++)
            {
                std::cout << ".";
            }

            this->setCurrentFloor(upRequest->getDestinationFloor());
            std::cout << "\nArrived at " << this->getCurrentFloor() << std::endl;

            this->openDoors();
            this->closeDoors();
        }
        std::cout << "Finished processing all the up requests." << std::endl;
}

void PassengerElevator::processDownRequests()
{
    while (!passengerDownQueue.empty())
        {
            Request *downRequest = passengerDownQueue.top();
            passengerDownQueue.pop();

            if (this->getCurrentFloor() == downRequest->getDestinationFloor())
            {
                std::cout << "Currently on floor " << this->getCurrentFloor() << ". No movement as destination is the same." << std::endl;
                continue;
            }
            std::cout << "The current floor is " << this->getCurrentFloor() << ". Next stop: " << downRequest->getDestinationFloor() << std::endl;

            std::cout << "Moving ";
            for (int i = 0; i < 3; i++)
            {
                std::cout << ".";
            }

            this->setCurrentFloor(downRequest->getDestinationFloor());
            std::cout << "\nArrived at " << this->getCurrentFloor() << std::endl;

            this->openDoors();
            this->closeDoors();
        }
        std::cout << "Finished processing all the down requests." << std::endl;
}

void PassengerElevator::processRequests()
{
     if (this->getState() == State::GOING_UP || this->getState() == State::IDLE)
        {
            processUpRequests();
            if (!passengerDownQueue.empty())
            {
                std::cout << "Now processing down requests..." << std::endl;
                processDownRequests();
            }
        }
        else
        {
            processDownRequests();
            if (!passengerUpQueue.empty())
            {
                std::cout << "Now processing up requests..." << std::endl;
                processUpRequests();
            }
        }
}
