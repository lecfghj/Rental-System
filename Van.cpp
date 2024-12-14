#include "Van.h"
#include <iostream>

Van::Van(std::string initID, int initNumSeats, std::string initMake, std::string initModel, double initCap, int initMaxWeight)
{
    ID = initID;
    numSeats = initNumSeats;
    make = initMake;
    model = initModel;
    storageCapacity = initCap;
    isAvailable = true;
    maxWeight = initMaxWeight;
}

void Van::displayDetails() const
{
    std::cout << "Type: " << getType() << "\n"
              << "Model: " << model << "\n"
              << "Make: " << make << "\n"
              << "Storage: " << storageCapacity << " liters.\n"
              << "ID: " << ID << "\n"
              << "Availability: " << isAvailable << "\n"
              << "Maximim weight carried: " << maxWeight << "kg.\n"
              << "Number of Seats: " << numSeats << std::endl;
}
std::string Van::getType() const
{
    return "Van";
}

int Van::getMaxWeight() const
{
    return maxWeight;
}
