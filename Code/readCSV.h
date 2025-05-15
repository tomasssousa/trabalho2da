#pragma once

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "Truck.h"
#include "Pallet.h"

using namespace std;

/**
* @brief Function to load Data from a TruckAndPallets CSV file!
* @param filename file which we will fetch the data
*/
inline void loadTruck(const std::string &filename) {
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

        // verify if the string is empty
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
            Truck truck;
            truck.capacity = stoi(capacity);
            truck.pallets = stoi(pallets);
            truckvec.push_back(truck);

            std::cout << "[INFO] Parsed: Capacity='" << truck.capacity << "', Pallets='" << truck.pallets << "'\n";

        } catch (const std::exception &e) {
            std::cerr << "[FATAL] Error converting line: " << line << " -> " << e.what() << std::endl;
        }
    }

    file.close();
}

/**
* @brief Function to load Data from a Pallets CSV file!
* @param filename file which we will fetch the data
*/
inline void loadPallets(const std::string &filename) {
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
            Pallet pallet;
            int palletId = stoi(id);
            pallet.weight = stoi(weight);
            pallet.profit = stoi(profit);
            palletmap[palletId] = pallet;

            std::cout << "[INFO] Parsed: Id='" << palletId << "', Weight='" << pallet.weight << "', Profit='" << pallet.profit << "'\n";

        } catch (const std::exception &e) {
            std::cerr << "[FATAL] Error converting line: " << line << " -> " << e.what() << std::endl;
        }
    }

    file.close();
}