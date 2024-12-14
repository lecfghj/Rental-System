#ifndef VAN_H
#define VAN_H
#include "Vehicle.h"
/**
 * @class Van
 * A class representing a van.
 *
 * The Van class extends the Vehicle class, adding a field for maximum weight capacity
 */
class Van : public Vehicle
{
private:
    int maxWeight; ///< Field representing maximum weight a van can carry
public:
    /**
     * Constructs a Van object with the specified attributes.
     *
     * @param initID The ID of the van.
     * @param initNumSeats The number of seats in the van.
     * @param initMake The make of the van.
     * @param initModel The model of the van.
     * @param initCap The storage capacity of the van in liters.
     * @param initMaxWeight The maximum weight capacity of the van in kilograms.
     */
    Van(std::string initID, int initNumSeats, std::string initMake, std::string initModel, double initCap, int initMaxWeight);
    /**
     *  Displays the details of the van.
     *
     * Overrides the displayDetails method of the Vehicle class.
     */
    void displayDetails() const override;
    /**
     * Gets the type of the vehicle.
     *
     * Overrides the getType method of the Vehicle class to return "Van".
     *
     * @return A string representing the type of the vehicle.
     */
    std::string getType() const override;
    /**
     * Gets the maximum weight capacity of the van.
     *
     * @return The maximum weight capacity of the van in kilograms.
     */
    int getMaxWeight() const;
};

#endif