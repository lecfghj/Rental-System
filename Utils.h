#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include "Vehicle.h"

/**
 * @class Utils
 * A utility class providing common helper functions.
 *
 * The Utils class contains methods for string trimming, searching, parsing, and vector manipulation.
 */
class Utils
{
public:
    /**
     * Trims whitespaces from a string.
     *
     * @param str The input string to be trimmed.
     * @return A new string with whitespaces removed.
     */
    std::string trim(const std::string &str);
    /**
     * This template function checks if the specified object exists within a vector.
     *
     * @tparam T The type of elements stored in the vector.
     * @param vector The vector to search.
     * @param object The object to check for existence in the vector.
     * @return True if the object is found; otherwise, false.
     */
    template <typename T>
    bool contains(std::vector<T> vector, T object)
    {
        for (int i = 0; i < vector.size(); i++)
        {
            if (vector[i] == object)
            {
                return true;
            }
        }
        return false;
    }

    /**
     * Splits a string in the format "key:value" into a pair of strings.
     *
     * @param input Input string in "key:value" format.
     * @return A pair containing the key and value extracted from the string.
     */
    std::pair<std::string, std::string> parseKeyValue(std::string input);
    /**
     * Splits an input string (comma-separated) of key and values in "key:value" format
     * into a list of key-value pairs.
     *
     * @param input Input search string to parse.
     * @return A vector of key-value pairs extracted from the input string.
     */
    std::vector<std::pair<std::string, std::string>> parseSearchInput(std::string input);
    /**
     * Extracts the first element from a given string until the first whitespace,
     * then removes it from the string.
     *
     * @param line Reference to the input string.
     * @return The extracted first element as a string.
     */
    std::string getFirstElement(std::string &line);

    /*
    template <typename ValueType>
    std::vector<std::pair<std::string, ValueType>> parseSearchInputTemp(std::string& input) {
        // Initialize a vector of pairs string : value
        std::vector<std::pair<std::string, ValueType>> result;

        int start = 0;
        int end = input.find(',');

        while (start < input.size()) {
            std::string segment = input.substr(start, end - start);

            // Use the provided parsing function for the key-value pair
            std::pair<std::string, ValueType> keyValue = parseKeyValue(segment);

            result.push_back(keyValue);

            start = end + 1;
            end = input.find(',', start);
            if (end == std::string::npos) {
                end = input.size(); // Process the last segment
            }
        }

        return result;
    }
    */

    /**
     * Iterates over the given vector to find and remove all instances of a specified object.
     *
     * @tparam T The type of elements stored in the vector.
     * @param vector The vector from which the object will be removed.
     * @param object The object to remove from the vector.
     */
    template <typename T>
    static void removeObject(std::vector<T> &vector, T object)
    {
        // Loop through the vector and remove the object
        for (size_t i = 0; i < vector.size(); ++i)
        {
            if (vector[i] == object)
            {
                vector.erase(vector.begin() + i);
                --i; // Adjust index after removal
            }
        }
    }
};

#endif