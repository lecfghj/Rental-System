#include "RentalCompany.h"

RentalCompany::RentalCompany()
{
    allVehicles = {};
    availableVehicles = {};
    currentCustomers = {};
}

RentalCompany::~RentalCompany()
{
}

void RentalCompany::addVehicle(Vehicle *vehicle)
{
    // Validate input
    if (vehicle == NULL)
    {
        std::cout << "Invalid vehicle." << std::endl;
        return;
    }
    // Check if vehicle already exist in the system
    for (int i = 0; i < allVehicles.size(); i++)
    {
        if (allVehicles[i] == vehicle)
        {
            std::cout << "Vehicle already in the list." << std::endl;
            return;
        }
    }
    // Check if vehicle with the same ID exists explicitly
    for (int j = 0; j < allVehicles.size(); j++)
    {
        if (allVehicles[j]->getID() == vehicle->getID())
        {
            std::cout << "Vehicle with such ID already exists" << std::endl;
            return;
        }
    }
    // Add vehicle to the system
    allVehicles.push_back(vehicle);
    availableVehicles.push_back(vehicle);

    std::cout << "Vehicle added successfully!" << std::endl;
}

void RentalCompany::removeVehicle(Vehicle *vehicle)
{
    // Validate input
    if (vehicle == NULL)
    {
        std::cout << "Invalid vehicle." << std::endl;
        return;
    }
    // Validate it exists in the system
    if (!utils.contains(allVehicles, vehicle))
    {
        std::cout << "No such vehicle in the system" << std::endl;
        return;
    }
    // Check if already rented
    if (!utils.contains(availableVehicles, vehicle))
    {
        std::cout << "Vehicle is currently rented, please wait to remove" << std::endl;
        return;
    }
    // Remove from the system
    utils.removeObject(availableVehicles, vehicle);
    utils.removeObject(allVehicles, vehicle);
    std::cout << "Vehicle removed" << std::endl;
}

void RentalCompany::addCustomer(Customer *customer)
{
    if (customer == NULL)
    {
        std::cout << "Invalid customer." << std::endl;
        return;
    }
    if (customer->getCustomerID() == "")
    {
        int n = currentCustomers.size();
        std::string ID = std::to_string(n + 1);
        customer->setCustomerID(ID);
    }
    for (int i = 0; i < currentCustomers.size(); i++)
    {
        if (currentCustomers[i]->getCustomerID() == customer->getCustomerID())
        {
            std::cout << "Customer with such ID already exists." << std::endl;
            return;
        }
    }

    currentCustomers.push_back(customer);
    std::cout << "Customer added successfully." << std::endl;
}

void RentalCompany::removeCustomer(Customer *customer)
{
    // Validate parameters
    if (customer == NULL)
    {
        std::cout << "Invalid customer." << std::endl;
        return;
    }
    // Valiudate if customer exists in the system
    if (!utils.contains(currentCustomers, customer))
    {
        std::cout << "No such customer in the system." << std::endl;
        return;
    }
    // Validate if customer isn't renting any vehicles
    if (!(customer->getRentedVehicles().empty()))
    {
        std::cout << "Customer is currently renting vehicles, return vehicles before removing.";
        return;
    }
    // Remove customer
    utils.removeObject(currentCustomers, customer);
}

void RentalCompany::rentVehicle(Customer *customer, Vehicle *vehicle)
{
    // Validate input
    if (customer == NULL || vehicle == NULL)
    {
        std::cout << "Invalid customer or vehicle." << std::endl;
        return;
    }
    // Check if customer exists in the system
    if (!utils.contains(currentCustomers, customer))
    {
        std::cout << "No such customer in the list." << std::endl;
        return;
    }
    // Check if vehicle exists in the system
    if (!utils.contains(availableVehicles, vehicle))
    {
        if (!utils.contains(allVehicles, vehicle))
        {
            std::cout << "No such vehicle in the system." << std::endl;
            return;
        }
        else
        {
            std::cout << "Vehicle is already rented." << std::endl;
            return;
        }
    }
    // Check if vehicle available
    if (!vehicle->getIfAvailable())
    {
        std::cout << "Vehicle already rented." << std::endl;
        return;
    }
    // Rent vehicle to a customer
    customer->rentVehicle(vehicle);
    // Remove vehicle from available vehicles vector
    utils.removeObject(availableVehicles, vehicle);
    std::cout << "Vehicle has been rented to a customer successfully." << std::endl;
}

void RentalCompany::returnVehicle(Customer *customer, Vehicle *vehicle)
{
    // Check if parameters are valid
    if (customer == NULL || vehicle == NULL)
    {
        std::cout << "Invalid customer or vehicle." << std::endl;
        return;
    }
    // Check if customer exists in the system
    if (!utils.contains(currentCustomers, customer))
    {
        std::cout << "No such customer in the list." << std::endl;
        return;
    }
    // Check if vehicle exists in the system
    if (!utils.contains(allVehicles, vehicle))
    {
        std::cout << "No such vehicle in the system." << std::endl;
        return;
    }
    // Check if a vehicle is rented by a customer
    if (!utils.contains(customer->getRentedVehicles(), vehicle))
    {
        std::cout << "This customer doesn't rent given vehicle." << std::endl;
        return;
    }
    // Return vehicle, add it back to available vehicles vector
    availableVehicles.push_back(vehicle);
    customer->returnVehicle(vehicle);
    std::cout << "Vehicle has been returned from a customer." << std::endl;
}

void RentalCompany::displayAvailableVehicles() const
{
    std::cout << "Displaying available vehicles. " << std::endl;
    for (int i = 0; i < availableVehicles.size(); i++)
    {
        availableVehicles[i]->displayDetails();
    }
}

void RentalCompany::saveVehiclesToFile(const std::string &filename)
{
    // Initialize file output stream
    std::ofstream outFile(filename);
    // Check if file stream is valid
    if (!outFile)
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    // Loop through each vehicle in the system
    for (Vehicle *vehicle : allVehicles)
    {

        std::string type = vehicle->getType();
        type = (type == "Vehicle") ? "" : (type + " ");
        // Handle vehicles based on their type
        if (type == "Van ")
        {

            // Van* van = (Van*)vehicle;
            Van *van = dynamic_cast<Van *>(vehicle);
            // Check if van is valid
            if (van == NULL)
            {
                std::cout << "Null pointer for van" << endl;
                return;
            }

            // van->displayDetails();
            // Write details of a van to the file
            outFile << type << van->getID() << " \"" << van->getMake() << "\" \"" << van->getModel() << "\" "
                    << van->getNumSeats() << " " << van->getStorageCap() << " " << van->getMaxWeight() << " "
                    << (van->getIfAvailable() ? 1 : 0) << "\n";
        }
        else if (type == "Car ")
        {
            // Car* car = (Car*)vehicle;
            Car *car = dynamic_cast<Car *>(vehicle);
            // Check if car is valid
            if (car == nullptr)
            {
                std::cout << "Null pointer for car" << endl;
                return;
            }

            // car->displayDetails();
            // Write details of a car to the file
            outFile << type << car->getID() << " \"" << car->getMake() << "\" \"" << car->getModel() << "\" "
                    << car->getNumSeats() << " " << car->getStorageCap() << " \"" << car->getFuelType() << "\" "
                    << (car->getIfAvailable() ? 1 : 0) << "\n";
        }
        else if (type == "Truck ")
        {
            // Truck* truck = (Truck*)vehicle;
            Truck *truck = dynamic_cast<Truck *>(vehicle);
            // Check if truck is valid
            if (!truck)
            {
                std::cout << "Null pointer for truck" << endl;
                return;
            }

            // truck->displayDetails();
            // Write details of a truck to the file
            outFile << type << truck->getID() << " \"" << truck->getMake() << "\" \"" << truck->getModel() << "\" "
                    << truck->getNumSeats() << " " << truck->getStorageCap() << " " << truck->getHeight() << " "
                    << (truck->getIfAvailable() ? 1 : 0) << "\n";
        }
        else
        { // General Vehicle

            // vehicle->displayDetails();
            // Write the details of general vehicle to the file
            outFile << type << vehicle->getID() << " \"" << vehicle->getMake() << "\" \"" << vehicle->getModel() << "\" "
                    << vehicle->getNumSeats() << " " << vehicle->getStorageCap() << " "
                    << (vehicle->getIfAvailable() ? 1 : 0) << "\n";
        }
    }
    // Close file stream
    outFile.close();
    std::cout << "Vehicles saved successfully to " << filename << "\n";
}

void RentalCompany::saveCustomersToFile(const std::string &filename)
{
    // Open file output stream
    std::ofstream outFile(filename);
    // Check if file stream is valid
    if (!outFile)
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    // Loop through each customer
    for (Customer *customer : currentCustomers)
    {
        std::string name = customer->getName();
        std::string ID = customer->getCustomerID();
        // Write name and ID to the file
        outFile << ID << " " << name << " ";
        // Loop through each rented vehicle and write their IDs to the file
        vector<Vehicle *> rentedVehicles = customer->getRentedVehicles();
        for (Vehicle *vehicle : rentedVehicles)
        {
            std::string vehicleID = vehicle->getID();
            outFile << vehicleID << " ";
        }
        outFile << "\n";
    }
    // Close file stream
    outFile.close();
    std::cout << "Customers saved successfully to " << filename << "\n";
}

void RentalCompany::loadVehiclesFromFile(const std::string &filename)
{
    // Initialize file stream
    std::ifstream inFile(filename);
    // Check if file stream is valid
    if (!inFile)
    {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }
    // Clear vehicles lists
    allVehicles.clear();
    availableVehicles.clear();
    // Initialize variables
    std::string type, id, make, model, fuelType;
    int numSeats, availability, maxWeight;
    double storageCap, height;
    // Loop through every value in file
    while (inFile >> type)
    {
        if (inFile.fail())
        {
            std::cerr << "Error reading van data from file." << std::endl;
            return;
        }

        if (type == "Van")
        {
            Van *van;
            // Read in ID
            inFile >> id;
            std::getline(inFile, make, '"');  // Start reading at double quotes
            std::getline(inFile, make, '"');  // Read until second double quotes
            std::getline(inFile, model, '"'); // Start reading at double quotes
            std::getline(inFile, model, '"'); // Read until second double quotes
            // Read in remaining values
            inFile >> numSeats >> storageCap >> maxWeight >> availability;
            // Ensure types are correct
            numSeats = (int)numSeats;
            storageCap = (double)storageCap;
            maxWeight = (int)maxWeight;
            availability = (bool)availability;
            // Create a van with read in values
            van = new Van(id, numSeats, make, model, storageCap, maxWeight);
            van->setAvailability(availability);

            // van->displayDetails();
            // Add a van to a list of all vehicles

            allVehicles.push_back(van);
            // addVehicle(van);
            //  If it's available, aslo add it to list of available vehicles
            if (availability)
            {
                availableVehicles.push_back(van);
            }
        }
        else if (type == "Car")
        {
            Car *car;
            // Read in ID
            inFile >> id;
            std::getline(inFile, make, '"');  // Start reading at first double quotes
            std::getline(inFile, make, '"');  // Read until second double quotes
            std::getline(inFile, model, '"'); // Start reading at first double quotes
            std::getline(inFile, model, '"'); // Read until second double quotes
            // Read it remaining values
            inFile >> numSeats >> storageCap;
            // Read in a value between double quotes
            std::getline(inFile, fuelType, '"');
            std::getline(inFile, fuelType, '"');
            // Read in remaining value
            inFile >> availability;
            // Instantiate a car
            car = new Car(id, numSeats, make, model, storageCap, fuelType);
            car->setAvailability(availability);

            // car->displayDetails();
            //  Add it to a list of all vehicles
            allVehicles.push_back(car);
            // If available add to a list of available vehicles
            if (availability)
            {
                availableVehicles.push_back(car);
            }
        }
        else if (type == "Truck")
        {
            Truck *truck;
            // Read in ID
            inFile >> id;
            std::getline(inFile, make, '"');  // Start reading at double quotes
            std::getline(inFile, make, '"');  // Read until second double quotes
            std::getline(inFile, model, '"'); // Start reading at double quotes
            std::getline(inFile, model, '"'); // Read until second double quotes
            // Read in remaining values
            inFile >> numSeats >> storageCap >> height >> availability;
            // Instantiate a truck
            truck = new Truck(id, numSeats, make, model, storageCap, height);
            truck->setAvailability(availability);

            // truck ->displayDetails();
            //  Add a truck to all vehicles list
            allVehicles.push_back(truck);
            // If it's available, add to a list of available vehicles
            if (availability)
            {
                availableVehicles.push_back(truck);
            }
        }
        else
        {
            id = type; // Set the ID to the type value read earlier

            std::getline(inFile, make, '"');
            std::getline(inFile, make, '"');
            std::getline(inFile, model, '"');
            std::getline(inFile, model, '"');
            inFile >> numSeats >> storageCap >> availability;

            // Instantiate a new vehicle with read in values
            Vehicle *vehicle = new Vehicle(id, numSeats, make, model, storageCap);
            vehicle->setAvailability(availability);

            // vehicle -> displayDetails();
            //
            allVehicles.push_back(vehicle);
            if (vehicle)
            {
                availableVehicles.push_back(vehicle);
            }
        }
    }
    // Close file stream
    inFile.close();

    std::cout << "Vehicles loaded.\n"
              << endl;
}

void RentalCompany::loadCustomersFromFile(const std::string &filename)
{
    Utils utils;
    // Create input file stream
    std::ifstream inFile(filename);
    // Check if file stream is valid
    if (!inFile)
    {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }
    // Clear vectorm of customers
    currentCustomers.clear();
    // Initialize variables
    std::string ID, name, vehicleID;
    std::string line;

    while (std::getline(inFile, line))
    {
        // Trim the line
        line = utils.trim(line);

        if (line.empty())
        {
            continue; // Skip empty lines
        }
        // Get ID and name form the file
        ID = utils.getFirstElement(line);
        name = utils.getFirstElement(line);
        // If Id or name are invalid, skip to the next line
        if (ID.empty() || name.empty())
        {
            std::cerr << "Wrong data format in input file" << std::endl;
            continue;
        }
        // Initialize customer with read in values
        Customer *loadedCustomer = new Customer(name);
        loadedCustomer->setCustomerID(ID);
        currentCustomers.push_back(loadedCustomer);
        // addCustomer(loadedCustomer);
        //  Loop through remaining values in the line
        while (!line.empty())
        {
            // Get first element of the line then rtim it
            vehicleID = utils.getFirstElement(line);
            vehicleID = utils.trim(vehicleID);
            // If it's a valid vehicle, rent it to a customer
            if (vehicleID != "")
            {
                Vehicle *rentedVehicle = findVehicleByID(vehicleID);
                if (rentedVehicle == nullptr)
                {
                    // If no valid vehicles found, notify user
                    std::cerr << "Vehicle ID " << vehicleID << " from the file doesn't match with any existent vehicles" << std::endl;
                    continue;
                }
                else
                {
                    loadedCustomer->rentVehicle(rentedVehicle);
                }
            }
        }
    }
    std::cout << "Customers loaded.\n"
              << endl;
}

Vehicle *RentalCompany::compareParam(const std::string &key, std::string &value, vector<Vehicle *> vehicles)
{
    // std::cout << "Key for searchBy: " << key << "\n"
    // << "Value: " << value << "\n" << std::endl;

    for (int i = 0; i < vehicles.size(); i++)
    {
        Vehicle *vehicle = vehicles[i];
        vehicle->displayDetails();

        // ID is a string
        if (key == "ID" && vehicle->getID() == value)
        {
            std::cout << "ID matched.\n"
                      << std::endl;
            return vehicle;
        }
        // Make is a string
        else if (key == "Make" && vehicle->getMake() == value)
        {
            std::cout << "Make matched.\n"
                      << vehicle->getMake() << std::endl;

            return vehicle; // Found the vehicle by Make
        }
        // Model is a string
        else if (key == "Model" && vehicle->getModel() == value)
        {
            std::cout << "Model matched.\n"
                      << std::endl;
            return vehicle; // Found the vehicle by Model
        }
        // Seats is expected to be an integer
        else if (key == "Seats")
        {
            try
            {
                int intValue = std::stoi(value); // Convert string to int
                if (vehicle->getNumSeats() == intValue)
                {
                    std::cout << "Number of seats matched.\n"
                              << std::endl;
                    return vehicle; // Found the vehicle by number of seats
                }
            }
            catch (const std::invalid_argument &)
            {
                // Handle conversion error
                std::cout << "Conversion error, invalid string to int.\n"
                          << std::endl;
                continue;
            }
        }
        // Storage is expected to be a float/double
        else if (key == "Storage")
        {
            try
            {
                float floatValue = std::stof(value); // Convert string to float
                if (vehicle->getStorageCap() == floatValue)
                {
                    std::cout << "Storage capacity matched.\n"
                              << std::endl;
                    return vehicle; // Found the vehicle by storage capacity
                }
            } // Handle conversion error
            catch (const std::invalid_argument &)
            {
                std::cout << "Conversion error, invalid string to float.\n"
                          << std::endl;
                continue;
            }
        }
    }

    return nullptr; // No vehicle found with that key and value
}

Vehicle *RentalCompany::findVehicleByID(std::string vehicleID)
{
    // Loop through all vehicles and compare IDs
    for (Vehicle *vehicle : allVehicles)
    {
        if (vehicle->getID() == vehicleID)
        {
            // If found a match, return it
            return vehicle;
        }
    }
    // In no match found return null pointer
    return nullptr;
}

Customer *RentalCompany::findCustomer(std::string customerID, std::string customerName)
{
    for (Customer *customer : currentCustomers)
    {
        if (customer->getName() == customerName && customer->getCustomerID() == customerID)
        {
            return customer;
        }
    }
    return nullptr;
}

std::vector<Vehicle *> RentalCompany::searchByMultiple(std::vector<Vehicle *> currentVehicles, std::string input)
{
    std::vector<std::pair<std::string, std::string>> searchParams = utils.parseSearchInput(input);

    // Iterate through each search parameter (key-value pair)
    for (int i = 0; i < searchParams.size(); ++i)
    {
        std::string key = searchParams[i].first;
        std::string value = searchParams[i].second;

        key = utils.trim(key);
        value = utils.trim(value);

        std::vector<Vehicle *> filteredVehicles;

        // Filter the current list of vehicles based on the current key-value pair
        for (int j = 0; j < currentVehicles.size(); ++j)
        {
            Vehicle *vehicle = currentVehicles[j];

            // Check if the vehicle matches the criteria for this key and value
            if (key == "ID" && vehicle->getID() == value)
            {
                filteredVehicles.push_back(vehicle);
            }
            else if (key == "Make" && vehicle->getMake() == value)
            {
                filteredVehicles.push_back(vehicle);
            }
            else if (key == "Model" && vehicle->getModel() == value)
            {
                filteredVehicles.push_back(vehicle);
            }
            else if (key == "Seats")
            {
                try
                {
                    int intValue = std::stoi(value);
                    if (vehicle->getNumSeats() == intValue)
                    {
                        filteredVehicles.push_back(vehicle);
                    }
                }
                catch (const std::invalid_argument &)
                {
                    // Handle invalid string to int conversion
                    std::cout << "Conversion error, invalid string to int.\n";
                    continue;
                }
            }
            else if (key == "Storage")
            {
                try
                {
                    float floatValue = std::stof(value);
                    if (vehicle->getStorageCap() == floatValue)
                    {
                        filteredVehicles.push_back(vehicle);
                    }
                }
                catch (const std::invalid_argument &)
                {
                    // Handle invalid string to float conversion
                    std::cout << "Conversion error, invalid string to float.\n";
                    continue;
                }
            }
        }

        // Update the list of current vehicles to the filtered list
        currentVehicles = filteredVehicles;

        // Exit early if no vehicles remain
        if (currentVehicles.empty())
        {
            break;
        }
    }

    return currentVehicles;
}
