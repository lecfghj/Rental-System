#ifndef RENTAL_COMPANY_H
#define RENTAL_COMPANY_H

#include "Vehicle.h"
#include "Customer.h"
#include "Utils.h"
#include "Car.h"
#include "Van.h"
#include "Truck.h"

#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;

/**
 * @class RentalCompany
 * Manages all aspects of a vehicle rental company.
 *
 * Handles the management of vehicles and customers, vehicle rental/return logic,
 * vehicle search functionalities, and saving/loading to/from files.
 */
class RentalCompany
{
    vector<Vehicle *> allVehicles;       ///< Field representing all vehicles in the rental company
    vector<Vehicle *> availableVehicles; ///< Field representing only available vehicles in rental company
    vector<Customer *> currentCustomers; ///< Field representing current customers of the rental company
    Utils utils;                         ///< Represent an instance of utility helper class

public:
    RentalCompany();  ///< Default constructor for the Rental Company class
    ~RentalCompany(); ///< Default destructor for the Rental COmpany class

    /**
     * Getter for all vehicles managed by the company.
     * @return Vector of pointers to all vehicles managed by the company.
     */
    vector<Vehicle *> getAllVehicles()
    {
        return allVehicles;
    }
    /**
     * Getter for all customers in the system.
     * @return Vector of pointers to all customers in the rental company.
     */
    vector<Customer *> getCustomers()
    {
        return currentCustomers;
    }
    /**
     * Getter for available vehicles in the system.
     * @return Vector of pointers to currently available vehicles.
     */
    vector<Vehicle *> getAvailableVehicles()
    {
        return availableVehicles;
    }
    /**
     * Adds a vehicle to the available vehicles list.
     * @param vehicle Pointer to the Vehicle object to add.
     */
    void addVehicle(Vehicle *vehicle);
    /**
     * Removes a vehicle from the available vehicles list.
     * @param vehicle Pointer to the Vehicle object to remove.
     */
    void removeVehicle(Vehicle *vehicle);
    /**
     * Adds a new customer to the customer list.
     * @param customer Pointer to the Customer object to add.
     */
    void addCustomer(Customer *customer);
    /**
     * Removes a customer from the customer list.
     * @param customer Pointer to the Customer object to remove.
     */
    void removeCustomer(Customer *customer);
    /**
     * Allows a customer to rent a vehicle.
     * @param customer Pointer to the Customer object renting the vehicle.
     * @param vehicle Pointer to the Vehicle object being rented.
     */
    void rentVehicle(Customer *customer, Vehicle *vehicle);
    /**
     * Handles the return of a rented vehicle.
     * @param customer Pointer to the Customer object returning the vehicle.
     * @param vehicle Pointer to the Vehicle object being returned.
     */
    void returnVehicle(Customer *customer, Vehicle *vehicle);
    /**
     * Displays a list of currently available vehicles.
     */
    void displayAvailableVehicles() const;
    /**
     * Saves the vehicle data to a specified file.
     * @param filename Name of the file to save data to.
     */
    void saveVehiclesToFile(const std::string &filename);
    /**
     * Saves the customer data to a specified file.
     * @param filename Name of the file to save data to.
     */
    void saveCustomersToFile(const std::string &filename);
    /**
     * Loads vehicle data from a specified file.
     * @param filename Name of the file to load data from.
     */
    void loadVehiclesFromFile(const std::string &filename);
    /**
     * Loads customer data from a specified file.
     * @param filename Name of the file to load data from.
     */
    void loadCustomersFromFile(const std::string &filename);
    /**
     * Compares a given key-value pair against a list of vehicles for search.
     *
     * @param key Search key to use (e.g., "ID", "Make").
     * @param value Value to match against the vehicles' attributes.
     * @param vehicles List of Vehicle pointers to search within.
     * @return Pointer to the matched Vehicle if found; nullptr otherwise.
     */
    Vehicle *compareParam(const std::string &key, std::string &value, vector<Vehicle *> vehicles);
    /**
     * Finds a vehicle by ID.
     * @param vehicleID The ID to search for.
     * @return Pointer to the Vehicle object if found; nullptr otherwise.
     */
    Vehicle *findVehicleByID(std::string vehicleID);
    /**
     * Finds a specific customer by ID and name.
     * @param customerID The customer ID to search for.
     * @param customerName The customer's name to search for.
     * @return Pointer to the Customer object if found; nullptr otherwise.
     */
    Customer *findCustomer(std::string customerID, std::string customerName);
    /**
     * Template function that looks for a vehicle by key and value.
     *
     * @tparam T Type parameter representing the attribute's type to compare.
     * @param key The key to search by (e.g., ID, Make, Model).
     * @param value The value to match the key against.
     * @return Pointer to the Vehicle object if found; nullptr otherwise.
     */
    template <typename T>
    Vehicle *searchByTemplate(const std::string &key, const T &value)
    {
        for (Vehicle *vehicle : allVehicles)
        {
            if (key == "ID" && vehicle->getID() == value)
            {
                return vehicle; // Found the vehicle by ID
            }
            else if (key == "Make" && vehicle->getMake() == value)
            {
                return vehicle; // Found the vehicle by Make
            }
            else if (key == "Model" && vehicle->getModel() == value)
            {
                return vehicle; // Found the vehicle by Model
            }
            else if (key == "Seats" && vehicle->getNumSeats() == value)
            {
                return vehicle; // Found the vehicle by number of seats
            }
            else if (key == "Storage" && vehicle->getStorageCap() == value)
            {
                return vehicle; // Found the vehicle by storage capacity
            }
        }
        return nullptr; // No vehicle found with that key and value
    }
    /**
     * Searches vehicles based on multiple criteria provided as input.
     * @param currentVehicles List of vehicles to search within.
     * @param input Search string in form of "key:value, key:value, key:value...".
     * @return Filtered list of pointers to vehicles that satisfy search criteria.
     */
    std::vector<Vehicle *> searchByMultiple(std::vector<Vehicle *> currentVehicles, std::string input);

    /*
    template <typename T>
    std::vector<Vehicle*> searchByMultipleTemplate(std::vector<Vehicle*> currentVehicles, const std::string& input)
    {
        // Parse the input string into search parameters
        std::vector<std::pair<std::string, T>> searchParams = parseSearchInput<T>(input);

        for (int i = 0; i < searchParams.size(); ++i) {
            std::string key = searchParams[i].first;
            T value = searchParams[i].second;

            std::vector<Vehicle*> filteredVehicles;

            for (int j = 0; j < currentVehicles.size(); ++j) {
                Vehicle* vehicle = currentVehicles[j];

                // Reuse the searchBy function
                if (searchBy(key, value) != nullptr) {
                    filteredVehicles.push_back(vehicle);
                }
            }

        // Update the list
        currentVehicles = filteredVehicles;

        // Exit early if no vehicles remain
        if (currentVehicles.empty()) {
            break;
        }
    }
        return currentVehicles;
    }
    */
};

#endif