#ifndef PALLET_H
#define PALLET_H

#include <map>


// Structure to store the pallets
struct Pallet{
    // the Pallets weight
    int weight;
    // the Pallets profit
    int profit;
};


// Map to identify each Pallet by its id
std:: map<int, struct Pallet> palletmap;

#endif //PALLET_H