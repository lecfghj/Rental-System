#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"

/**
 * @class Truck
 * A class representing a truck, derived from the Vehicle class.
 *
 * The Truck class extends the Vehicle base class by adding height parameter.
 */
class Truck : public Vehicle
{
private:
    double height; ///< The height of the truck in meters.
public:
    /**
     * Constructor for the Truck class.
     *
     * Constructs a Truck object with initial parameters.
     *
     * @param initID The ID of the truck.
     * @param initNumSeats The number of seats in the truck.
     * @param initMake The make of the truck.
     * @param initModel The model of the truck.
     * @param initCap The storage capacity of the truck in liters.
     * @param initHeight The height of the truck in meters.
     */
    Truck(std::string initID, int initNumSeats, std::string initMake, std::string initModel, double initCap, double initHeight);
    /**
     * Displays the details of the truck.
     *
     * Overrides the base class method.
     */
    void displayDetails() const override;
    /**
     * Gets the type of the vehicle.
     *
     * Overrides the base class method.
     *
     * @return A string representing the type of the vehicle.
     */
    std::string getType() const override;
    /**
     * Gets the height of the truck.
     *
     * @return The height of the truck in meters.
     */
    double getHeight() const;
};

#endif