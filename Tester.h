#ifndef TESTER_H
#define TESTER_H

#include "RentalCompany.h"
#include "Utils.h"
#include "Car.h"
#include "Van.h"
#include "Truck.h"
#include "Customer.h"
#include "Vehicle.h"

#include <iostream>
#include <vector>
#include <string>

class Tester
{
public:
    // Test case to add a car to the rental company.
    bool addCar();

    // Test case to add a van to the rental company.
    bool addVan();

    // Test case to add a truck to the rental company.
    bool addTruck();

    bool addNewCustomer();

    bool existingCustomerRent();

    void testSearch();

    void testSaveLoad();

    void testSaveLoadCustomers();

    void runTests();

    // Test case to remove a vehicle from the rental company.
    bool removeVehicle();

    // Test case to remove a customer from the rental company.
    bool removeCustomer();
};

#endif // TESTER_H
