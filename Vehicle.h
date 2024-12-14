#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

/**
 * @class Vehicle
 * A class representing a generic vehicle.
 *
 * The Vehicle class serves as a base class for different types of vehicles.
 */
class Vehicle
{
protected:
    bool isAvailable;       ///< Flag indicating whether a vehicle is available or not
    std::string ID;         ///< ID for the vehicle
    std::string make;       ///< Make of the vehicle
    std::string model;      ///< Model of the vehicle
    int numSeats;           ///< Number of available seats in the vehicle
    double storageCapacity; ///< Storage capacity of the vehicles in liters

public:
    // Constructors
    Vehicle(); ///< Default constructor
    /**
     * Constructor for the Vehicle class with initial parameters.
     *
     * @param initID ID of the vehicle.
     * @param initNumSeats The number of seats in the vehicle.
     * @param initMake The make of the vehicle.
     * @param initModel The model of the vehicle.
     * @param initCap The storage capacity of the vehicle in liters.
     */
    Vehicle(std::string initID, int initNumSeats, std::string initMake, std::string initModel, double initCap);

    // Destructor required for dynamic cast
    virtual ~Vehicle() = default; ///< Default destructor

    /**
     * Gets the ID of the vehicle.
     *
     * @return The ID of the vehicle.
     */
    std::string getID() const;
    /**
     * Gets the model of the vehicle.
     *
     * @return The model of the vehicle.
     */
    std::string getModel() const;
    /**
     * Gets the make of the vehicle.
     *
     * @return The make of the vehicle.
     */
    std::string getMake() const;
    /**
     * Gets the number of seats in the vehicle.
     *
     * @return The number of seats in the vehicle.
     */
    int getNumSeats() const;
    /**
     * Gets the storage capacity of the vehicle in liters.
     *
     * @return The storage capacity of the vehicle in liters.
     */
    double getStorageCap() const;
    /**
     * Checks if the vehicle is available for rent.
     *
     * @return True if the vehicle is available, false otherwise.
     */
    bool getIfAvailable() const;
    /**
     * Marks the vehicle as rented.
     *
     * Updates the availability status to indicate that the vehicle is no longer available.
     */
    void rent();
    /**
     * Sets the availability status of the vehicle.
     *
     * @param ifAvailable True to make the vehicle available, false to mark it as unavailable.
     */
    void setAvailability(bool ifAvailable);
    /**
     * Marks the vehicle as returned.
     *
     * Updates the availability status to indicate that the vehicle is available.
     */
    void returnVehicle();
    /**
     *  Displays the details of the vehicle.
     *
     * This method is intended to be overridden by derived classes to provide specific details.
     */
    virtual void displayDetails() const; // To be overriden
    /**
     * Gets the type of the vehicle.
     *
     * This method is intended to be overridden by derived classes to specify the vehicle type.
     *
     * @return A string representing the type of the vehicle.
     */
    virtual std::string getType() const; // To be overriden
};

#endif