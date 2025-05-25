#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/**
* @brief Function to load Data from a TruckAndPallets CSV file!
* @param parsedCapacity variable, which will be used to save the truck's Capacity in terms of Weight
* @param parsedPallets variable, which will be used to save the truck's Capacity in terms of the number of Pallets
* @param filename file which we will fetch the data
*/

inline void loadTruck(int &parsedCapacity, int &parsedPallets, const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream temp(line);
        std::string capacity, pallets;
        std::getline(temp, capacity, ',');
        std::getline(temp, pallets);

        //verify if the string is empty
        if (capacity.empty() || pallets.empty()) {
            std::cerr << "[ERROR] Invalid line skipped (missing truck capacity or number of pallets): " << line << std::endl;
            continue;
        }

        //verify if capacity and pallets are digits
        if (!std::all_of(capacity.begin(), capacity.end(), ::isdigit) ||
            !std::all_of(pallets.begin(), pallets.end(), ::isdigit)) {
            std::cout << "[ERROR] Non-numeric field(s): Capacity='" << capacity << "', Pallets='" << pallets << "'\n";
            continue;
        }

        try {
            parsedCapacity = stoi(capacity);
            parsedPallets = stoi(pallets);

            std::cout << "[INFO] Parsed: Capacity='" << parsedCapacity << "', Pallets='" << parsedPallets << "'\n";

        } catch (const std::exception &e) {
            std::cerr << "[FATAL] Error converting line: " << line << " -> " << e.what() << std::endl;
        }
    }

    file.close();
}


/**
* @brief Function to load Data from a Pallets_xx.csv file
* @param parsedWeights variable, which will be used to store all the weights of all the Pallets
* @param parsedProfits variable, which will be used to store the profits of all the Pallets
* @param filename file which we will fetch the data
*/
inline void loadPallets(std::vector<int>& parsedWeights,
                        std::vector<int>& parsedProfits,
                        const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "[FATAL] Error opening file: " << filename << "\n";
        return;
    }

    // helper to trim spaces, tabs, CR, LF
    auto trim = [](std::string &s) {
        const char* ws = " \t\n\r";
        auto start = s.find_first_not_of(ws);
        auto end   = s.find_last_not_of(ws);
        if (start == std::string::npos) {
            s.clear();
        } else {
            s = s.substr(start, end - start + 1);
        }
    };

    std::string line;
    // skip header line
    if (!std::getline(file, line)) return;

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        // remove trailing CR if present
        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        std::stringstream ss(line);
        std::string id, weightStr, profitStr;

        if (!std::getline(ss, id, ',') ||
            !std::getline(ss, weightStr, ',') ||
            !std::getline(ss, profitStr)) {
            std::cerr << "[ERROR] Malformed line, skipping: " << line << "\n";
            continue;
        }

        // trim each field
        trim(id);
        trim(weightStr);
        trim(profitStr);

        // ensure weight and profit are non-empty and all digits
        auto isNumber = [](const std::string &t) {
            return !t.empty() && std::all_of(t.begin(), t.end(),
                                             [](unsigned char c){ return std::isdigit(c); });
        };
        if (!isNumber(weightStr) || !isNumber(profitStr)) {
            std::cerr << "[ERROR] Non-numeric field(s), skipping: "
                      << "weight='" << weightStr << "', profit='" << profitStr << "'\n";
            continue;
        }

        try {
            parsedWeights .push_back(std::stoi(weightStr));
            parsedProfits .push_back(std::stoi(profitStr));
            std::cout << "[INFO] Parsed: weight=" << weightStr
                      << ", profit=" << profitStr << "\n";
        } catch (const std::exception &e) {
            std::cerr << "[FATAL] Conversion error on line: " << line
                      << " -> " << e.what() << "\n";
        }
    }
}



