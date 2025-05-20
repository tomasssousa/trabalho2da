#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <cmath>
#include <math.h>
#include <bitset>
#include <iostream>

#include "Pallet.h"
#include <iostream>
#include <map>
#include <vector>
#include "Write_output.h"

using namespace std;

/**
* @brief This function is responsible for calculating the optimal setup, using the brute force method.
* @param Pallets A map with the pallets to be used in the problem, identifiable by their id.
* @param n Number of Pallets.
* @param maxWeight Max possible weight.
* @param usedItems[] An array with items used marked in true or false             Could be changed to store the id of the used ones
* @return The integer with the optimal value.
*/
unsigned int knapsackBF(const std::vector<int> &profits,const std::vector<int> &weights, unsigned int n, unsigned int maxWeight, std::vector<bool> &usedItems,unsigned int &usedWeight) {
    //total number of possibilities for arranging the truck, not counting weight limitations
    unsigned int Iteration = pow(2,n);
    unsigned int MaxPossibleValue = 0;
    for(unsigned int i = 0; i < Iteration; i++) {
        //binary representation of the truck layout.
        std::bitset<2048> binarySub(i);
        int IterationP=0;
        int IterationW=0;
        for (int j=0; j<n;j++) {
            IterationP+=profits[j]*binarySub[j];
            IterationW+=weights[j]*binarySub[j];
        }
        if (IterationW<=maxWeight && (IterationP>MaxPossibleValue) || (IterationP == MaxPossibleValue && usedWeight > IterationW)) {
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