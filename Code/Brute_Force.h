#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <cmath>
#include <math.h>
#include <bitset>
#include <vector>

using namespace std;

/**
* @brief This function is responsible for calculating the optimal setup using the brute force method.
* @param profits Vector of profits for each item.
* @param weights Vector of weights for each item.
* @param n Number of items.
* @param maxWeight Max possible weight capacity.
* @param usedItems Vector with items used marked as true or false.
* @param usedWeight Reference to store the total used weight.
* @return The integer with the optimal value.
*/
unsigned int knapsackBF(const std::vector<int> &profits,const std::vector<int> &weights, unsigned int n, unsigned int maxWeight, std::vector<bool> &usedItems,unsigned int &usedWeight) {
    //total number of possibilities for arranging the truck, not counting weight limitations
    unsigned int Iteration = pow(2,n);
    unsigned int MaxPossibleValue = 0;
    for(unsigned int i = 0; i < Iteration; i++) {
        //binary representation of the truck layout.
        std::bitset<2048> binarySub(i);
        unsigned int IterationP=0;
        unsigned int IterationW=0;
        for (int j=0; j<n;j++) {
            IterationP+=profits[j]*binarySub[j];
            IterationW+=weights[j]*binarySub[j];
        }
        if (IterationW <= maxWeight && ((IterationP > MaxPossibleValue) || (IterationP == MaxPossibleValue && usedWeight > IterationW))) {
            MaxPossibleValue=IterationP;
            usedWeight = IterationW;
            for (int j=0; j<n;j++) {
                if (binarySub[j]==1) {usedItems[j]=true;}
                else {usedItems[j]=false;}
            }
        }
    }

    return MaxPossibleValue;
}

#endif //BRUTE_FORCE_H