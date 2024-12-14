#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

/**
 * @class Car
 * A class representing a car.
 *
 * The Car class extends the Vehicle class, adding a new field for fuel type.
 */
class Car : public Vehicle
{
private:
    std::string fuelType; ///< Field representing fuel type
public:
    /**
     * Constructs a Car object with the initial parameters.
     *
     * @param initID The ID of the car.
     * @param initNumSeats The number of seats in the car.
     * @param initMake The make of the car.
     * @param initModel The model of the car.
     * @param initCap The storage capacity of the car in liters.
     * @param initFuel The type of fuel the car uses.
     */
    Car(std::string initID, int initNumSeats, std::string initMake, std::string initModel, double initCap, std::string initFuel);
    /**
     * Displays the details of the car.
     *
     * Overrides the displayDetails method of the Vehicle class.
     */
    void displayDetails() const override;
    /**
     * Gets the type of the vehicle.
     *
     * Overrides the getType method of the Vehicle class to return "Car".
     *
     * @return A string representing the type of the vehicle.
     */
    std::string getType() const override;
    /**
     * Gets the fuel type of the car.
     *
     * @return A string representing the fuel type of the car.
     */
    std::string getFuelType() const;
};

#endif