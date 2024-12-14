#include "Utils.h"

/*std::vector<std::pair<std::string, std::string>> Utils::parseSearchInput(const std::string &input)
{
    std::vector<std::pair<std::string, std::string>> result;

    int start = 0;
    int end = input.find(',');

    while (start < input.size()) {
        std::string segment = input.substr(start, end - start);

        int colonPos = segment.find(':');
        if (colonPos != std::string::npos) {
            std::string key = segment.substr(0, colonPos);
            std::string value = segment.substr(colonPos + 1);


            key = trim(key);
            value = trim(value);

            result.push_back(std::make_pair(key, value));
        }

        start = end + 1;
        end = input.find(',', start);
        if (end == std::string::npos) {
            end = input.size(); // Process the last segment
        }
    }

    return result;
}
*/

std::string Utils::trim(const std::string &str)
{
    // Find index of the first and last characters that are not whitespaces
    size_t start = str.find_first_not_of(' ');
    size_t end = str.find_last_not_of(' ');

    // Check if the string is empty
    if (start == std::string::npos)
    {
        return "";
    }

    // Extract the trimmed string
    std::string result = str.substr(start, end - start + 1);
    return result;
}

std::pair<std::string, std::string> Utils::parseKeyValue(std::string input)
{
    // Find the position of the colon (:) separator
    int colonPos = input.find(':');
    if (colonPos == std::string::npos)
    {
        throw std::invalid_argument("Invalid input format.");
    }

    // Extract the key and value as strings
    std::string key = trim(input.substr(0, colonPos));
    std::string valueStr = trim(input.substr(colonPos + 1));

    // std::cout << "Parsed key:value: " << key << ": " << valueStr << "\n" << std::endl;
    return {key, valueStr};
}

std::vector<std::pair<std::string, std::string>> Utils::parseSearchInput(std::string input)
{
    std::vector<std::pair<std::string, std::string>> result;

    int start = 0;
    int end = input.find(','); // FInd index of first comma
    // Loop through input, extracting segments and parsing them into key-value pairs
    while (start < input.size())
    {
        std::string segment = input.substr(start, end - start); // Extract the current segment

        // Use the provided parsing function for the key-value pair
        std::pair<std::string, std::string> keyValue = parseKeyValue(segment);
        // Parse the segment into a key-value pair and add to the result
        result.push_back(keyValue);
        // Move to the next segment
        start = end + 1;              // Redefine start
        end = input.find(',', start); // Find next comma
        if (end == std::string::npos)
        {
            end = input.size(); // Process the last segment
        }
    }

    return result;
}

std::string Utils::getFirstElement(std::string &line)
{
    // Find the first space in the string
    int i = line.find(' ');

    // Handle edge cases
    if (i == std::string::npos)
    {
        // No spaces, return the entire line
        std::string firstElement = line;
        line.clear(); // Clear the line entirely
        return firstElement;
    }

    // Extract substring and erase it from the line
    std::string firstElement = line.substr(0, i);
    line.erase(0, i + 1);

    return firstElement;
}
