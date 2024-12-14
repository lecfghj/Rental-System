#ifndef MENU_H
#define MENU_H
#include "RentalCompany.h"
#include "Tester.h"

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Menu
 * This class represents the menu system for interacting with the rental system.
 *
 * The Menu class provides an interface for the user to interact with the rental system.
 */
class Menu
{
private:
    bool running;          ///< Field representing state of the menu
    RentalCompany company; ///< Field representing rental company
    Tester tester;         ///< Field representing tester for running tests
    Utils utils;           ///< Field representing class with utility functions

public:
    Menu(); ///< Default constructor

    /**
     * Starts the menu and initiates the interaction loop with the user.
     */
    void run();
    /**
     * Displays the main menu to the user with available options.
     */
    void showMenu();
    /**
     * Handles the process of adding a vehicle to the rental company.
     */
    void handleAddVehicle();
    /**
     * Handles the process of adding a customer to the rental company.
     */
    void handleAddCustomer();
    /**
     * Handles the process of removing customer form the rental company
     */
    void handleRemoveCustomer();
    /**
     * Handles the process of removing vehicle from the rental company
     */
    void handleRemoveVehicle();
    /**
     * Handles the process of renting a vehicle.
     */
    void handleRentVehicle();
    /**
     * Handles the process of returning a vehicle.
     */
    void handleReturnVehicle();
    /**
     * Handles the process of saving data of the rental company.
     */
    void handleSaveData();
    /**
     * Handles the process of loading data to rental company.
     */
    void handleLoadData();
    /**
     * Handles the process of listing available vehicles.
     */
    void handleListVehicles();
    /**
     * Handles the process of searching for a vehicle.
     */
    void handleSearch();
};

#endif