#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Vehicle.h"

/**
 * @class Customer
 * A class representing a customer in the vehicle rental system.
 *
 * The Customer class has the details of a customer, including their ID, name,
 * and the vehicles they have rented. It provides methods to manage rented vehicles
 * and display customer information.
 */
class Customer
{
private:
    std::string customerID;                ///< Field representing a customer ID
    std::string customerName;              ///< Field representing customer name
    std::vector<Vehicle *> rentedVehicles; ///< Field representing vehicles customer is renting

public:
    /**
     * Constructs a Customer object with initial parameters.
     *
     * @param initName The name of the customer.
     */
    Customer(std::string initName);

    /**
     * Gets the ID of the customer.
     *
     * @return The ID of the customer.
     */
    std::string getCustomerID() const;
    /**
     * Gets the name of the customer.
     *
     * @return The name of the customer.
     */
    std::string getName() const;
    /**
     * Gets the list of vehicles rented by the customer.
     *
     * @return A vector of pointers to vehicles rented by the customer.
     */
    std::vector<Vehicle *> getRentedVehicles();
    /**
     * Sets the ID of the customer.
     *
     * @param newID The new ID for the customer.
     */
    void setCustomerID(std::string newID);
    /**
     * Adds a vehicle to the list of rented vehicles.
     *
     * @param vehicle A pointer to the vehicle to be rented.
     */
    void rentVehicle(Vehicle *vehicle);
    /**
     * Removes a vehicle from the list of rented vehicles.
     *
     * @param vehicle A pointer to the vehicle to be returned.
     */
    void returnVehicle(Vehicle *vehicle);
    /**
     * Displays the details of the customer.
     *
     * Prints the customer's ID, name, and the list of rented vehicles.
     */
    void displayDetails() const;
};

#endif