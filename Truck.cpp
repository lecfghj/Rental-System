#include "Truck.h"

#include <iostream>

Truck::Truck(std::string initID, int initNumSeats, std::string initMake, std::string initModel, double initCap, double initHeight)
{
    ID = initID;
    numSeats = initNumSeats;
    make = initMake;
    model = initModel;
    storageCapacity = initCap;
    isAvailable = true;
    height = initHeight;
}

void Truck::displayDetails() const
{
    std::cout << "Type: " << getType() << "\n"
              << "Model: " << model << "\n"
              << "Make: " << make << "\n"
              << "Storage: " << storageCapacity << " liters.\n"
              << "ID: " << ID << "\n"
              << "Availability: " << isAvailable << "\n"
              << "Height: " << height << "\n"
              << "Number of Seats: " << numSeats << std::endl;
}
std::string Truck::getType() const
{
    return "Truck";
}
double Truck::getHeight() const
{
    return height;
};