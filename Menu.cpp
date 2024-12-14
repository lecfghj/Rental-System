#include "Menu.h"

#include <iostream>
#include <string>
#include <vector>

Menu::Menu()
{
    company = RentalCompany();
    tester = Tester();
    running = true;
    utils = Utils();
}

/**
 * @brief Displays the menu to the user.
 */
void Menu::showMenu()
{
    // Show menu options
    std::cout << "\n---------------- Rental System  -----------------\n";
    std::cout << "1. Add Vehicle\n";
    std::cout << "2. Add Customer\n";
    std::cout << "3. Rent Vehicle\n";
    std::cout << "4. Return Vehicle\n";
    std::cout << "5. Save Data\n";
    std::cout << "6. Load Data\n";
    std::cout << "7. List available vehicles\n";
    std::cout << "8. Search for vehicles\n";
    std::cout << "9. Run tests.\n";
    std::cout << "10. Remove vehicle.\n";
    std::cout << "11. Remove customer.\n";
    std::cout << "12. Exit\n";
    std::cout << "----------------------------------------------------\n";
}

/**
 * @brief Handles the addition of a vehicle to the rental company.
 */
void Menu::handleAddVehicle()
{
    // Initialize variables
    std::string ID, make, model, fuelType;
    int seats, maxWeight;
    double storageCap, height;
    Vehicle *vehicle = nullptr;
    Car *car = nullptr;
    Van *van = nullptr;
    Truck *truck = nullptr;

    // Prompt user to choose one of the options
    std::cout << "Please choose a type of the vehicle: \n"
              << std::endl;
    std::cout << "1. General Vehicle\n";
    std::cout << "2. Car\n";
    std::cout << "3. Van\n";
    std::cout << "4. Truck\n";

    int choice;
    if (!(std::cin >> choice))
    {
        std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
        std::cin.clear();                 // Clear error state
        std::cin.ignore(100000000, '\n'); // Flush input buffer
        return;                           // Exit early on invalid input
    }

    // Use switch on user input
    switch (choice)
    {
    case 1:
        // If user chose general vehicle, ask for details for general vehicle
        std::cout << "\nEnter ID: ";
        std::cin >> ID;
        std::cin.ignore();
        std::cout << "Enter make: ";
        std::getline(std::cin, make);
        std::cout << "Enter model: ";
        std::getline(std::cin, model);
        std::cout << "Enter number of seats: ";
        while (!(std::cin >> seats))
        {
            std::cout << "Invalid input. Please enter a valid number of seats: ";
            std::cin.clear();                   // Clear error flag
            std::cin.ignore(10000000000, '\n'); // Flush buffer
        }

        std::cout << "Enter storage capacity: ";
        while (!(std::cin >> storageCap))
        {
            std::cout << "Invalid input. Please enter a valid number for storage capacity: ";
            std::cin.clear();
            std::cin.ignore(1000000000000, '\n');
        }
        // Instatiate a vehicle with given values
        vehicle = new Vehicle(ID, seats, make, model, storageCap);
        // Add a vehicle to the company
        company.addVehicle(vehicle);
        break;

    case 2:
        // If user chose a car, ask for details for a car
        std::cout << "\nEnter ID: ";
        std::cin >> ID;
        std::cin.ignore();
        std::cout << "Enter make: ";
        std::getline(std::cin, make);
        std::cout << "Enter model: ";
        std::getline(std::cin, model);
        std::cout << "Enter number of seats: ";
        while (!(std::cin >> seats))
        {
            std::cout << "Invalid input. Please enter a valid number of seats: ";
            std::cin.clear();                   // Clear error flag
            std::cin.ignore(10000000000, '\n'); // Flush buffer
        }

        std::cout << "Enter storage capacity: ";
        while (!(std::cin >> storageCap))
        {
            std::cout << "Invalid input. Please enter a valid number for storage capacity: ";
            std::cin.clear();
            std::cin.ignore(1000000000000, '\n');
        }
        std::cout << "Enter fuel type: ";
        std::cin >> fuelType;
        // Instatiate new car with given values
        car = new Car(ID, seats, make, model, storageCap, fuelType);
        // Add a car to the company
        company.addVehicle(car);
        break;

    case 3:
        // If user chose a van, ask for details for a van
        std::cout << "\nEnter ID: ";
        std::cin >> ID;
        std::cin.ignore();
        std::cout << "Enter make: ";
        std::getline(std::cin, make);
        std::cout << "Enter model: ";
        std::getline(std::cin, model);
        std::cout << "Enter number of seats: ";
        while (!(std::cin >> seats))
        {
            std::cout << "Invalid input. Please enter a valid number of seats: ";
            std::cin.clear();                   // Clear error flag
            std::cin.ignore(10000000000, '\n'); // Flush buffer
        }

        std::cout << "Enter storage capacity: ";
        while (!(std::cin >> storageCap))
        {
            std::cout << "Invalid input. Please enter a valid number for storage capacity: ";
            std::cin.clear();
            std::cin.ignore(1000000000000, '\n');
        }
        std::cout << "Enter maximum weight a van can carry: ";
        while (!(std::cin >> maxWeight))
        {
            std::cout << "Invalid input. Please enter a valid number for maximum weight: ";
            std::cin.clear();
            std::cin.ignore(100000000000, '\n');
        }
        // Instantiate a van with given values
        van = new Van(ID, seats, make, model, storageCap, maxWeight);
        // Add it to the company
        company.addVehicle(van);
        break;

    case 4:
        // If user chose a truck, ask for details for a truck
        std::cout << "\nEnter ID: ";
        std::cin >> ID;
        std::cin.ignore();
        std::cout << "Enter make: ";
        std::getline(std::cin, make);
        std::cout << "Enter model: ";
        std::getline(std::cin, model);
        std::cout << "Enter number of seats: ";
        while (!(std::cin >> seats))
        {
            std::cout << "Invalid input. Please enter a valid number of seats: ";
            std::cin.clear();                   // Clear error flag
            std::cin.ignore(10000000000, '\n'); // Flush buffer
        }

        std::cout << "Enter storage capacity: ";
        while (!(std::cin >> storageCap))
        {
            std::cout << "Invalid input. Please enter a valid number for storage capacity: ";
            std::cin.clear();
            std::cin.ignore(1000000000000, '\n');
        }
        std::cout << "Enter height: ";
        while (!(std::cin >> height))
        {
            std::cout << "Invalid input. Please enter a valid number for height: ";
            std::cin.clear();
            std::cin.ignore(100000000000, '\n');
        }
        // Instantiate a truck with given values
        truck = new Truck(ID, seats, make, model, storageCap, height);
        // Add a truck to the company
        company.addVehicle(truck);
        break;
    }
}

/**
 * Handles the addition of a customer to the rental company.
 */
void Menu::handleAddCustomer()
{
    std::string name, id;
    std::cout << "\nEnter Customer ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Customer Name: ";
    std::getline(std::cin, name);

    Customer *customer = new Customer(name);
    customer->setCustomerID(id);
    company.addCustomer(customer);
}
/**
 * Handles removal of a customer from the rental company.
 */
void Menu::handleRemoveCustomer()
{
    // Ask user for customer data
    std::string name, id;
    std::cout << "\nEnter Customer ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Customer Name: ";
    std::getline(std::cin, name);
    // Remove customer
    Customer *customer = company.findCustomer(id, name);
    company.removeCustomer(customer);
}

void Menu::handleRemoveVehicle()
{ // Ask user for vehicle data
    std::string id;
    std::cout << "\nEnter vehicle ID: ";
    std::cin >> id;
    // Remove vehicle
    Vehicle *vehicle = company.findVehicleByID(id);
    company.removeVehicle(vehicle);
}

/**
 * Handles the renting of a vehicle to a customer.
 */
void Menu::handleRentVehicle()
{
    // Initialize variables
    std::string customerID, customerName, vehicleID;
    // Ask user for input
    std::cout << "\nEnter Customer ID: ";
    std::cin >> customerID;
    std::cout << "\nEnter Customer name: ";
    std::cin >> customerName;
    std::cout << "Enter Vehicle ID to rent: ";
    std::cin >> vehicleID;
    // Find customer and vehicle according to user input
    Customer *customer = company.findCustomer(customerID, customerName);
    Vehicle *vehicle = company.findVehicleByID(vehicleID);
    // Rent a vehicle to a customer
    company.rentVehicle(customer, vehicle);
}

/**
 * Handles the return of a vehicle by a customer.
 */
void Menu::handleReturnVehicle()
{
    // Initialize variables
    std::string customerID, customerName, vehicleID;
    // Ask user for input
    std::cout << "Enter Customer ID: \n";
    std::cin >> customerID;
    std::cout << "Enter Customer name: \n";
    std::cin >> customerName;
    std::cout << "Enter Vehicle ID to return: \n";
    std::cin >> vehicleID;
    // Find customer and vehicle according to user input
    Customer *customer = company.findCustomer(customerID, customerName);
    Vehicle *vehicle = company.findVehicleByID(vehicleID);
    // Return vehicle from a customer
    company.returnVehicle(customer, vehicle);
}

/**
 * Saves customer and vehicle data to files.
 */
void Menu::handleSaveData()
{
    // Save customer and vehicle data to files
    company.saveCustomersToFile("customers.txt");
    company.saveVehiclesToFile("vehicles.txt");
}

/**
 * Loads customer and vehicle data from files.
 */
void Menu::handleLoadData()
{
    // Load customer and vehicle data from files
    company.loadCustomersFromFile("customers.txt");
    company.loadVehiclesFromFile("vehicles.txt");
}
void Menu::handleListVehicles()
{
    // Get a vector of available vehicles
    vector<Vehicle *> vehicles = company.getAvailableVehicles();
    // Display details for each
    for (Vehicle *vehicle : vehicles)
    {
        std::cout << "-------------------\n";
        vehicle->displayDetails();
    }
}
void Menu::handleSearch()
{
    // Initialize utils
    Utils utils;
    // Give user some instructions
    std::cout << "Please enter search in format of key:value,key: value...\n"
              << "Separate each pair with semicolon(:), use comma(,) as delimiter.\n"
              << "You can search by ID:value,Make:value,Model:value,Seats:value,Storage:value.\n"
              << std::endl;
    // Read in user input
    std::string input;
    std::getline(std::cin, input); // Read the entire line of input

    //  Trim input
    input = utils.trim(input);
    // Initialize a vector for found vehicles
    vector<Vehicle *> foundVehicles;
    // Search for vehicles according to user input
    foundVehicles = company.searchByMultiple(company.getAllVehicles(), input);
    // Display found vehicles to user
    for (Vehicle *vehicle : foundVehicles)
    {
        std::cout << "-------------------\n";
        vehicle->displayDetails();
    }
}
void Menu::run()
{
    // Run while running flag is true
    while (running)
    {
        // Show menu options
        showMenu();
        // Initialize choice variable and read it in
        int choice;
        std::cout << "Enter your choice:\n";
        // std::cin >> choice;
        //  Input validation
        if (!(std::cin >> choice))
        {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();                         // Clear error
            std::cin.ignore(10000000000000000, '\n'); // Discard invalid input
            continue;                                 // Skip the rest of the loop
        }
        std::cin.ignore(10000000000000000, '\n'); // Clear buffer
        // Use switch on user input and handle it accordingly
        switch (choice)
        {
        case 1:
            handleAddVehicle();
            break;
        case 2:
            handleAddCustomer();
            break;
        case 3:
            handleRentVehicle();
            break;
        case 4:
            handleReturnVehicle();
            break;
        case 5:
            handleSaveData();
            break;
        case 6:
            handleLoadData();
            break;
        case 7:
            handleListVehicles();
            break;
        case 8:
            handleSearch();
            break;
        case 9:
            tester.runTests();
            break;
        case 10:
            handleRemoveVehicle();
            break;
        case 11:
            handleRemoveCustomer();
            break;
        case 12:
            std::cout << "Goodbye!" << std::endl;
            running = false;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;

            break;
        }
    }
}

int main()
{
    Menu menu = Menu();
    menu.run();

    return 0;
}
