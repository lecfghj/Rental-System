#include "Car.h"
#include <iostream>

Car::Car(std::string initID, int initNumSeats, std::string initMake, std::string initModel, double initCap, std::string initFuel)
{
    ID = initID;
    numSeats = initNumSeats;
    make = initMake;
    model = initModel;
    storageCapacity = initCap;
    isAvailable = true;
    fuelType = initFuel;
}

void Car::displayDetails() const
{
    std::cout << "Type: " << getType() << "\n"
              << "Model: " << model << "\n"
              << "Make: " << make << "\n"
              << "Storage: " << storageCapacity << " liters.\n"
              << "ID: " << ID << "\n"
              << "Availability: " << isAvailable << "\n"
              << "Fuel type: " << fuelType << "\n"
              << "Number of Seats: " << numSeats << std::endl;
}
std::string Car::getType() const
{
    return "Car";
}

std::string Car::getFuelType() const
{
    return fuelType;
};