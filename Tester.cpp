/**
 * This file contains test functions for the Rental Company System.
 * Includes functions to add vehicles, add customers, perform searches,
 * and validate save/load functionality.
 */

#include "RentalCompany.h"
#include "Utils.h"
#include "Car.h"
#include "Tester.h"

#include <string>
#include <vector>
#include <iostream>

/**
 * Test case to add a car to the rental company.
 *
 * @return True if the test ran successfully, false otherwise.
 */
bool Tester::addCar()
{
    Utils utils;

    // Create test car
    Vehicle *car = new Car(std::string("ABC12"), 4, std::string("Vauxhall"), std::string("Corsa"), 32.5, std::string("Electric"));
    // Add it to the company
    RentalCompany rentalCompany;
    rentalCompany.addVehicle(car);
    // Validate it hasbeen added properly
    vector<Vehicle *> allVehiclesVector = rentalCompany.getAllVehicles();
    if (utils.contains(allVehiclesVector, car))
    {
        std::cout << "Test addCar ran successfully.\n"
                  << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test addCar failed.\n"
                  << std::endl;
        return false;
    }
}

/**
 * Test case to add a van to the rental company.
 *
 * @return True if the test ran successfully, false otherwise.
 */
bool Tester::addVan()
{
    Utils utils;
    // Create test van
    Vehicle *van = new Van("VAN456", 2, "Ford", "Transit", 250, 2000);
    // Add it to a company
    RentalCompany rentalCompany;
    rentalCompany.addVehicle(van);
    // Validate it has been added properly
    std::vector<Vehicle *> allVehiclesVector = rentalCompany.getAllVehicles();
    if (utils.contains(allVehiclesVector, van))
    {
        std::cout << "Test addVan ran successfully.\n"
                  << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test addVan failed.\n"
                  << std::endl;
        return false;
    }
}

/**
 * Test case to add a truck to the rental company.
 *
 * @return True if the test ran successfully, false otherwise.
 */
bool Tester::addTruck()
{
    Utils utils;
    // Create test truck
    std::string testID = "TRUCK789";
    Vehicle *truck = new Truck(testID, 2, "Mercedes", "Actros", 100, 4.5);
    // Add it to the company
    RentalCompany rentalCompany;
    rentalCompany.addVehicle(truck);
    // Validate it has been added
    std::vector<Vehicle *> allVehiclesVector = rentalCompany.getAllVehicles();
    if (utils.contains(allVehiclesVector, truck))
    {
        std::cout << "Test addTruck ran successfully.\n"
                  << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test addTruck failed.\n"
                  << std::endl;
        return false;
    }
}

/**
 * Test case to add a new customer to the rental company.
 *
 * @return True if the test ran successfully, false otherwise.
 */
bool Tester::addNewCustomer()
{
    Utils utils;
    // Create test customer
    std::string name = "Christina";
    Customer *customer = new Customer(name);
    // Add a customer to the company
    RentalCompany rentalCompany;
    rentalCompany.addCustomer(customer);
    // Validate customer has been added
    vector<Customer *> customersVector = rentalCompany.getCustomers();
    if (utils.contains(customersVector, customer))
    {
        std::cout << "Test addNewCustomer ran successfully.\n"
                  << std::endl;
        return true;
    }
    else
    {
        std::cout << "Test addNewCustomer failed.\n"
                  << std::endl;
        return false;
    }
}

/**
 * Tests whether an existing customer can successfully rent a vehicle.
 *
 * @return bool True if the test succeeds, false otherwise.
 */
bool Tester::existingCustomerRent()
{
    RentalCompany company;
    // Create test customer
    std::string name = "Alice";
    Customer *customer = new Customer(name);
    customer->setCustomerID("001");
    company.addCustomer(customer);

    // Create test vehicles and add it to the company's inventory
    Vehicle *v1 = new Vehicle("V001", 5, "Ford", "Mustang", 50);
    company.addVehicle(v1);
    Vehicle *v2 = new Vehicle("V002", 5, "Ford", "Mustang", 50);
    company.addVehicle(v2);

    customer->rentVehicle(v1);
    customer->rentVehicle(v2);
    // Validate customer has rented vehicle
    if (customer->getRentedVehicles()[1]->getID() == "V002")
    {
        std::cout << "Test existingCustomerRent run successfully.\n"
                  << std::endl;
        return true;
    }
    std::cout << "Test existingCustomerRent failed.\n"
              << std::endl;
    return false;
}

/**
 * Function to test searching functionalities of the RentalCompany.
 *
 * This function performs multiple search tests by different parameters such as
 * make, number of seats, and model to verify the search capabilities.
 */
void Tester::testSearch()
{
    Utils utils;
    // Create test vehicles
    std::string testID = "ABC12";
    Vehicle *vehicle1 = new Vehicle(testID, 4, "Vauxhall", "Corsa", 32);
    Vehicle *vehicle2 = new Vehicle("CD234", 4, "Audi", "A6", 12);
    Vehicle *vehicle3 = new Vehicle("CD236", 3, "Audi", "A3", 12);
    Vehicle *vehicle4 = new Vehicle("EF567", 5, "Toyota", "Camry", 15);
    Vehicle *vehicle5 = new Vehicle("GH890", 5, "Honda", "Accord", 18);
    // Add all vehicles to the company
    RentalCompany rentalCompany;
    rentalCompany.addVehicle(vehicle1);
    rentalCompany.addVehicle(vehicle2);
    rentalCompany.addVehicle(vehicle3);
    rentalCompany.addVehicle(vehicle4);
    rentalCompany.addVehicle(vehicle5);

    std::vector<Vehicle *> allVehicles = rentalCompany.getAllVehicles();
    // Test case: Search by Make:Audi
    std::string input = "Make: Audi";
    std::vector<Vehicle *> foundVehicles = rentalCompany.searchByMultiple(allVehicles, input);
    // Real result
    std::cout << "Found vehicle for Make:Audi search:\n"
              << std::endl;
    for (int i = 0; i < foundVehicles.size(); i++)
    {
        Vehicle *vehicle = foundVehicles[i];
        vehicle->displayDetails();
    }

    std::vector<Vehicle *> predictedResult;
    predictedResult.push_back(vehicle2);
    predictedResult.push_back(vehicle3);

    // Expected result
    std::cout << "Expected result:\n"
              << std::endl;
    for (int i = 0; i < predictedResult.size(); i++)
    {
        Vehicle *vehicle = predictedResult[i];
        vehicle->displayDetails();
    }

    // Search by Seats:5
    std::string input2 = "Seats: 5";
    std::vector<Vehicle *> foundVehicles2 = rentalCompany.searchByMultiple(allVehicles, input2);

    std::cout << "\nSearch for Seats = 5\n"
              << std::endl;
    for (int i = 0; i < foundVehicles2.size(); i++)
    {
        Vehicle *vehicle = foundVehicles2[i];
        vehicle->displayDetails();
    }

    // Expected result
    std::cout << "Expected result:\n"
              << std::endl;
    vehicle4->displayDetails();
    vehicle5->displayDetails();

    // Search by Model: Corsa
    std::string input3 = "Model: Corsa";
    std::vector<Vehicle *> foundVehicles3 = rentalCompany.searchByMultiple(allVehicles, input3);

    std::cout << "\nSearch for Model = Corsa\n"
              << std::endl;
    for (int i = 0; i < foundVehicles3.size(); i++)
    {
        Vehicle *vehicle = foundVehicles3[i];
        vehicle->displayDetails();
    }

    // Expected result
    std::cout << "Expected result:\n"
              << std::endl;
    vehicle1->displayDetails();

    // Search by multiple parameters
    std::string input4 = "Make: Audi, Seats: 3";
    std::vector<Vehicle *> foundVehicles4 = rentalCompany.searchByMultiple(allVehicles, input4);

    std::cout << "\n Search for Make = Audi AND Seats = 3\n"
              << std::endl;
    for (int i = 0; i < foundVehicles4.size(); i++)
    {
        Vehicle *vehicle = foundVehicles4[i];
        vehicle->displayDetails();
    }

    // Expected result
    std::cout << "Expected result:\n"
              << std::endl;
    vehicle3->displayDetails();

    // Test Case 6: Search by multiple parameters (Make = Audi AND Seats = 5)
    std::string input6 = "Make: Audi, Seats: 5";
    std::vector<Vehicle *> foundVehicles6 = rentalCompany.searchByMultiple(allVehicles, input6);

    std::cout << "\nSearch for Make = Audi AND Seats = 5\n"
              << std::endl;
    if (foundVehicles6.empty())
    {
        std::cout << "No vehicles found.\n";
    }
    else
    {
        for (int i = 0; i < foundVehicles6.size(); i++)
        {
            Vehicle *vehicle = foundVehicles6[i];
            vehicle->displayDetails();
        }
    }

    // Predicted result
    std::cout << "Expected result:\nNo vehicles found.\n"
              << std::endl;

    delete vehicle1;
    delete vehicle2;
    delete vehicle3;
    delete vehicle4;
    delete vehicle5;

    return;
}

/**
 * Function to test saving and loading vehicle data to and from files.
 *
 * This function tests the save and load operations of vehicle data for the RentalCompany class.
 * It validates if vehicles are correctly saved to a file and loaded back from it.
 */
void Tester::testSaveLoad()
{
    std::cout << "Running testSaveLoad.\n"
              << std::endl;
    RentalCompany company;

    // Create test vehicles
    Vehicle *v1 = new Vehicle("V001", 4, "Toyota", "Corolla", 50);
    Vehicle *c1 = new Car("V002", 5, "Honda", "Civic", 45, "Petrol");
    Vehicle *v2 = new Van("V003", 2, "Ford", "Transit", 60, 1200);
    Vehicle *t1 = new Truck("V004", 3, "Volvo", "FH16", 80, 4.5);

    v1->setAvailability(true);
    c1->setAvailability(false);
    v2->setAvailability(true);
    t1->setAvailability(false);

    // Add vehicles to the company
    company.addVehicle(v1);
    company.addVehicle(c1);
    company.addVehicle(v2);
    company.addVehicle(t1);

    // Save vehicles to a file
    std::string filename = "test_vehicles.txt";
    company.saveVehiclesToFile(filename);

    company.loadVehiclesFromFile(filename);

    // Validate loaded vehicles
    vector<Vehicle *> loadedVehicles = company.getAllVehicles();
    if (loadedVehicles.size() == 4)
    {
        std::cout << "Correct number of vehicles loaded.\n"
                  << std::endl;
    }
    else
    {
        std::cout << "Incorrect number of vehicles loaded. Expected 4 but found " << loadedVehicles.size() << "\n"
                  << std::endl;
    }

    if (loadedVehicles.size() >= 4)
    {
        // Validate individual vehicles
        Vehicle *loadedV1 = loadedVehicles[0];
        if (loadedV1->getID() == "V001" &&
            loadedV1->getMake() == "Toyota" &&
            loadedV1->getModel() == "Corolla" &&
            loadedV1->getNumSeats() == 4 &&
            loadedV1->getStorageCap() == 50 &&
            loadedV1->getIfAvailable() == true)
        {
            std::cout << "Vehicle loaded correctly.\n"
                      << std::endl;
        }
        else
        {
            std::cout << "Vehicle did not load correctly.\n"
                      << std::endl;
        }
        // Cast to a car
        Car *loadedC1 = dynamic_cast<Car *>(loadedVehicles[1]);
        if (loadedC1 &&
            loadedC1->getID() == "V002" &&
            loadedC1->getMake() == "Honda" &&
            loadedC1->getModel() == "Civic" &&
            loadedC1->getNumSeats() == 5 &&
            loadedC1->getStorageCap() == 45 &&
            loadedC1->getFuelType() == "Petrol" &&
            loadedC1->getIfAvailable() == false)
        {
            std::cout << "Car loaded correctly.\n"
                      << std::endl;
        }
        else
        {
            std::cout << "Car did not load correctly.\n"
                      << std::endl;
        }
        // Cast to a van
        Van *loadedV2 = dynamic_cast<Van *>(loadedVehicles[2]);
        if (loadedV2 &&
            loadedV2->getID() == "V003" &&
            loadedV2->getMake() == "Ford" &&
            loadedV2->getModel() == "Transit" &&
            loadedV2->getNumSeats() == 2 &&
            loadedV2->getStorageCap() == 60 &&
            loadedV2->getMaxWeight() == 1200 &&
            loadedV2->getIfAvailable() == true)
        {
            std::cout << "Van loaded correctly.\n"
                      << std::endl;
        }
        else
        {
            std::cout << "Van did not load correctly.\n"
                      << std::endl;
        }
        // Cast to a truck
        Truck *loadedT1 = dynamic_cast<Truck *>(loadedVehicles[3]);
        if (loadedT1 &&
            loadedT1->getID() == "V004" &&
            loadedT1->getMake() == "Volvo" &&
            loadedT1->getModel() == "FH16" &&
            loadedT1->getNumSeats() == 3 &&
            loadedT1->getStorageCap() == 80 &&
            loadedT1->getHeight() == 4.5 &&
            loadedT1->getIfAvailable() == false)
        {
            std::cout << "Truck loaded correctly.\n"
                      << std::endl;
        }
        else
        {
            std::cout << "Truck did not load correctly.\n"
                      << std::endl;
        }
    }
}
/**
 * Tests saving and loading customers' data to/from a file.
 *
 * This function tests the save and load operations of customer data for the RentalCompany class.
 * It validates if customers are correctly saved to a file and loaded back from it.
 */
void Tester::testSaveLoadCustomers()
{
    std::cout << "Running testSaveLoadCustomers.\n"
              << std::endl;

    RentalCompany company;

    // Create test customers
    Customer *c1 = new Customer("Alice");
    c1->setCustomerID("101");
    Customer *c2 = new Customer("Bob");
    c2->setCustomerID("102");
    Customer *c3 = new Customer("Charlie");
    c3->setCustomerID("103");
    Customer *c4 = new Customer("David");
    c4->setCustomerID("104");
    Customer *c5 = new Customer("Eve");
    c5->setCustomerID("105");

    // Initialize test vehicles
    Vehicle *v1 = new Vehicle("V101", 5, "Ford", "Fiesta", 40);
    Vehicle *v2 = new Vehicle("V102", 6, "Audi", "Q8", 60);
    Vehicle *v3 = new Vehicle("V103", 4, "Nissan", "Micra", 30);
    Vehicle *v4 = new Vehicle("V104", 5, "Honda", "Civic", 35);
    Vehicle *v5 = new Vehicle("V105", 4, "Audi", "Q2", 35);
    Vehicle *v6 = new Vehicle("V106", 5, "Seat", "Ateca", 45);
    Vehicle *v7 = new Vehicle("V107", 5, "Peugeot", "2008", 50);

    // Set availability
    v1->setAvailability(true);
    v2->setAvailability(false);
    v3->setAvailability(true);
    v4->setAvailability(true);
    v5->setAvailability(false);
    v6->setAvailability(true);
    v7->setAvailability(true);

    // Add vehicles to the company
    company.addVehicle(v1);
    company.addVehicle(v2);
    company.addVehicle(v3);
    company.addVehicle(v4);
    company.addVehicle(v5);
    company.addVehicle(v6);
    company.addVehicle(v7);
    // Add customers to the company
    company.addCustomer(c1);
    company.addCustomer(c2);
    company.addCustomer(c3);
    company.addCustomer(c4);
    company.addCustomer(c5);
    // Rent test vehicles
    c1->rentVehicle(v1);
    c1->rentVehicle(v2);
    c2->rentVehicle(v3);
    c4->rentVehicle(v4);
    c4->rentVehicle(v5);
    c4->rentVehicle(v6);
    c5->rentVehicle(v7);

    // Save customers to a file
    std::string filename = "test_customers.txt";
    company.saveCustomersToFile(filename);

    // Reinitialize company with empty customer lists
    company = RentalCompany();

    // Add vehicles back to the company
    company.addVehicle(v1);
    company.addVehicle(v2);
    company.addVehicle(v3);
    company.addVehicle(v4);
    company.addVehicle(v5);
    company.addVehicle(v6);
    company.addVehicle(v7);
    // Load customers back
    company.loadCustomersFromFile(filename);
    // Validate number of loaded customers
    vector<Customer *> loadedCustomers = company.getCustomers();
    if (loadedCustomers.size() == 5)
    {
        std::cout << "Correct number of customers loaded.\n"
                  << std::endl;
    }
    else
    {
        std::cout << "Incorrect number of customers loaded. Expected 5 but found " << loadedCustomers.size() << "\n"
                  << std::endl;
    }
    // Validate each customer individually
    if (loadedCustomers.size() >= 5)
    {
        Customer *loadedC1 = loadedCustomers[0];
        if (loadedC1->getCustomerID() == "101" && loadedC1->getName() == "Alice" && loadedC1->getRentedVehicles()[0]->getID() == "V101" && loadedC1->getRentedVehicles()[1]->getID() == "V102")
        {
            std::cout << "Customer 1 loaded correctly.\n"
                      << std::endl;
        }
        else
        {
            std::cout << "Customer 1 did not load correctly.\n"
                      << std::endl;
        }

        Customer *loadedC2 = loadedCustomers[1];
        if (loadedC2->getCustomerID() == "102" && loadedC2->getName() == "Bob" && loadedC2->getRentedVehicles()[0]->getID() == "V103")
        {
            std::cout << "Customer 2 loaded correctly.\n"
                      << std::endl;
        }
        else
        {
            std::cout << "Customer 2 did not load correctly.\n"
                      << std::endl;
        }

        Customer *loadedC3 = loadedCustomers[2];
        if (loadedC3->getCustomerID() == "103" && loadedC3->getName() == "Charlie" && loadedC3->getRentedVehicles().empty())
        {
            std::cout << "Customer 3 loaded correctly.\n"
                      << std::endl;
        }
        else
        {
            std::cout << "Customer 3 did not load correctly.\n"
                      << std::endl;
        }

        Customer *loadedC4 = loadedCustomers[3];
        if (loadedC4->getCustomerID() == "104" && loadedC4->getName() == "David" && loadedC4->getRentedVehicles()[0]->getID() == "V104" && loadedC4->getRentedVehicles()[1]->getID() == "V105" && loadedC4->getRentedVehicles()[2]->getID() == "V106")
        {
            std::cout << "Customer 4 loaded correctly.\n"
                      << std::endl;
        }
        else
        {
            std::cout << "Customer 4 did not load correctly.\n"
                      << std::endl;
        }

        Customer *loadedC5 = loadedCustomers[4];
        if (loadedC5->getCustomerID() == "105" && loadedC5->getName() == "Eve" && loadedC5->getRentedVehicles()[0]->getID() == "V107")
        {
            std::cout << "Customer 5 loaded correctly.\n"
                      << std::endl;
        }
        else
        {
            std::cout << "Customer 5 did not load correctly.\n"
                      << std::endl;
        }
    }
}
/**
 * Runs all test functions.
 */
void Tester::runTests()
{
    addCar();
    addVan();
    addTruck();
    addNewCustomer();
    removeVehicle();
    removeCustomer();
    existingCustomerRent();
    testSearch();
    testSaveLoad();
    testSaveLoadCustomers();
}
bool Tester::removeVehicle()
{
    std::cout << "Running removeVehicle test." << std::endl;
    RentalCompany company;
    Utils utils;

    // Add a vehicle to the system
    Vehicle *vehicle1 = new Vehicle("V101", 5, "Ford", "Fiesta", 40);
    company.addVehicle(vehicle1);

    // Remove the vehicle
    company.removeVehicle(vehicle1);

    // Check if the vehicle was removed
    if (!utils.contains(company.getAllVehicles(), vehicle1))
    {
        std::cout << "Vehicle successfully removed." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Vehicle was not removed." << std::endl;
        return false;
    };
}
bool Tester::removeCustomer()
{
    std::cout << "Running removeCustomer test." << std::endl;
    RentalCompany company;
    Utils utils;

    // Add a customer to the system
    Customer *customer1 = new Customer("John Doe");
    company.addCustomer(customer1);

    // Remove the customer
    company.removeCustomer(customer1);

    // Check if the customer was removed
    if (!utils.contains(company.getCustomers(), customer1))
    {
        std::cout << "Customer successfully removed." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Customer was not removed." << std::endl;
        return false;
    }
}