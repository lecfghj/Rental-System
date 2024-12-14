#include "Customer.h"
#include "Utils.h"
#include <vector>
#include <iostream>

Customer::Customer(std::string initName)
{
    customerID = "";
    customerName = initName;
    rentedVehicles = {};
}

void Customer::rentVehicle(Vehicle *vehicle)
{
    // Mark vehcile as rented
    vehicle->rent();
    // Add new vehicle to the end of the vector
    rentedVehicles.push_back(vehicle);
}
void Customer::returnVehicle(Vehicle *vehicle)
{
    Utils utils;
    // Return vehicle
    vehicle->returnVehicle();
    // Remove from rented vehicles vector
    utils.removeObject(rentedVehicles, vehicle);
}
void Customer::displayDetails() const
{
    std::cout << "Customer ID: " << customerID << "\n"
              << "Customer name: " << customerName << "\n"
              << "Rented vehicles: "
              << "\n"
              << std::endl;
    // Check if customer rents any vehicles
    if (!rentedVehicles.empty())
    {
        // Display details for each rented vehicle
        for (int i = 0; i < rentedVehicles.size(); i++)
        {
            std::cout << "Vehicle " << i + 1 << ":\n"
                      << std::endl;
            rentedVehicles[i]->displayDetails();
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "none" << std::endl;
    }
}

std::string Customer::getCustomerID() const
{
    return customerID;
}

std::string Customer::getName() const
{
    return customerName;
}

std::vector<Vehicle *> Customer::getRentedVehicles()
{
    return rentedVehicles;
}

void Customer::setCustomerID(std::string newID)
{
    customerID = newID;
}
