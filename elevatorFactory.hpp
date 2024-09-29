#ifndef ELEVATORFACTORY_HPP
#define ELEVATORFACTORY_HPP
#include "passengerElevator.hpp"
#include "serviceElevator.hpp"
class ElevatorFactory 
{
public:
    Elevator* createElevator(ElevatorType type) {
        switch (type) {
            case ElevatorType::PASSENGER:
                return new PassengerElevator(1, false);
            case ElevatorType::SERVICE:
                return new ServiceElevator(1, false);
            default:
                throw std::invalid_argument("Unknown criteria.");
        }
    }
};
#endif // elevatorFactory_HPP