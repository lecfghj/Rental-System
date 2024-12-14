#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle()
{
    ID = "";
    numSeats = 0;
    make = "";
    model = "";
    storageCapacity = 0;
    isAvailable = false;
}

Vehicle::Vehicle(std::string initID, int initNumSeats, std::string initMake, std::string initModel, double initCap)
{
    ID = initID;
    numSeats = initNumSeats;
    make = initMake;
    model = initModel;
    storageCapacity = initCap;
    isAvailable = true;
}

void Vehicle::displayDetails() const
{
    std::cout << "ID: " << ID << "\n"
              << "Availability: " << isAvailable << "\n"
              << "Make: " << make << "\n"
              << "Model: " << model << "\n"
              << "Seats: " << numSeats << std::endl;
}

std::string Vehicle::getType() const
{
    return "Vehicle";
}

void Vehicle::setAvailability(bool ifAvailable)
{
    isAvailable = ifAvailable;
}

void Vehicle::returnVehicle()
{
    isAvailable = true;
}

std::string Vehicle::getMake() const
{
    return make;
}

int Vehicle::getNumSeats() const
{
    return numSeats;
}

double Vehicle::getStorageCap() const
{
    return storageCapacity;
}

bool Vehicle::getIfAvailable() const
{
    return isAvailable;
}

void Vehicle::rent()
{
    isAvailable = false;
}

std::string Vehicle::getID() const
{
    return ID;
}

std::string Vehicle::getModel() const
{
    return model;
}
