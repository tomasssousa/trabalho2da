#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <cmath>
#include <algorithm>
#include <vector>

/**
* @brief This function is responsible for calculating the optimal setup, using Dynamic Programming.
* @param profits Vector of profits for each item
* @param weights Vector of weights for each item
* @param n Number of Pallets.
* @param maxWeight Max possible weight.
* @param usedItems Vector with items used marked as true or false
* @param usedWeight Reference to store the total used weight
* @return The integer with the optimal value.
*/
unsigned int knapsackDP(const std::vector<int> &profits, const std::vector<int> &weights, unsigned int n, unsigned int maxWeight, std::vector<bool> &usedItems, unsigned int &usedWeight) {
    std::vector<std::vector<unsigned int>> maxValue(n, std::vector<unsigned int>(maxWeight + 1, 0));

    // Step 1: Initialize the DP matrix with the values for the base cases
    for(unsigned int k = 0; k <= maxWeight; k++) {
        maxValue[0][k] = (k >= weights[0]) ? profits[0] : 0;
    }

    // Step 2: Compute values of the DP matrix for the recursive cases
    for(unsigned int i = 1; i < n; i++) {
        for(unsigned int k = 0; k <= maxWeight; k++) {
            if(k < weights[i]) {
                maxValue[i][k] = maxValue[i - 1][k];
            } else {
                unsigned int valueUsingItemI = maxValue[i - 1][k - weights[i]] + profits[i];
                maxValue[i][k] = std::max(maxValue[i - 1][k], valueUsingItemI);
            }
        }
    }

    // Step 3: Build the solution
    std::fill(usedItems.begin(), usedItems.end(), false);
    unsigned int currentWeight = maxWeight;
    usedWeight = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(i == 0) {
            // Special check for the first item
            if(currentWeight >= weights[0] && maxValue[0][currentWeight] == profits[0]) {
                usedItems[0] = true;
                usedWeight += weights[0];
                currentWeight -= weights[0];
            }
        } else {
            // Check if item i was included in the optimal solution
            // Item i is included if removing it changes the optimal value
            if(maxValue[i][currentWeight] != maxValue[i-1][currentWeight]) {
                usedItems[i] = true;
                usedWeight += weights[i];
                currentWeight -= weights[i];
            }
        }
    }
    
    return maxValue[n-1][maxWeight];
}

#endif //DYNAMIC_PROGRAMMING_H