#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
* @brief Function to load Data from a TruckAndPallets CSV file!
* @param parsedCapacity variable which will be used to save the truck's Capacity in terms of Weight
* @param parsedPallets variable which will be used to save the truck's Capacity in terms of the number of Pallets
* @param filename file which we will fetch the data
*/
template<class T>
inline void loadTruck(int parsedCapacity, int parsedPallets, const std::string &filename) {
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
            std::cerr << "[ERROR] Non-numeric field(s): Capacity='" << capacity << "', Pallets='" << pallets << "'\n";
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
* @brief Function to load Data from a Pallets CSV file!
* @param parsedId variable which will be used to save the pallet's ID
* @param parsedWeight variable which will be used to save the pallet's Weight
* @param parsedProfit variable which will be used to save the pallet's Profit
* @param filename file which we will fetch the data
*/
template<class T>
inline void loadPallets(int parsedId, int parsedWeight, int parsedProfit, const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "[FATAL] Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream temp(line);
        std::string id, weight, profit;
        std::getline(temp, id, ',');
        std::getline(temp, weight, ',');
        std::getline(temp, profit);

        if (id.empty() || weight.empty() || profit.empty()) {
            std::cerr << "[ERROR] Empty field on line: " << line << std::endl;
            continue;
        }

        //verify if id and parking are digits
        if (!std::all_of(id.begin(), id.end(), ::isdigit) ||
            !std::all_of(weight.begin(), weight.end(), ::isdigit ||
            !std::all_of(profit.begin(), profit.end(), ::isdigit))) {
            std::cerr << "[ERROR] Non-numeric field(s): Id='" << id << "', Weight='" << weight << "', Profit='" << profit << "'\n";
            continue;
        }

        try {
            parsedId = stoi(id);
            parsedWeight = stoi(weight);
            parsedProfit = stoi(profit);

            std::cout << "[INFO] Parsed: Id='" << parsedId << "', Weight='" << parsedWeight << "', Profit='" << parsedProfit << "'\n";

        } catch (const std::exception &e) {
            std::cerr << "[FATAL] Error converting line: " << line << " -> " << e.what() << std::endl;
        }
    }

    file.close();
}