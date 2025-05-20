#ifndef GREEDY_H
#define GREEDY_H

#include <cmath>
#include <math.h>
#include <bitset>
#include <iostream>

#include "Pallet.h"
#include <iostream>
#include <map>
#include <vector>


unsigned int knapsackGreedyValue(const std::vector<int> &profits,const std::vector<int> &weights, unsigned int n, unsigned int maxWeight, std::vector<bool> &usedItems,unsigned int &usedWeight) {
    int MaxProfit=0;
    usedWeight=0;
    bool flag=false;
    bool PossibleItem=false;
    for(int i=0;i<n;i++) {usedItems[i]=false;}
    while (!flag) {
        double MaxTempRacio=0.0;
        int TPosition;
        for (int i=0; i<n; i++) {
            double TempRacio =static_cast<double>(profit[i])/weights[i];
            if (((TempRacio==MaxTempRacio && weights[i]<weights[TPosition])||TempRacio>MaxTempRacio) && weights[i]<=maxWeight && usedItems[i]==false) {
                MaxTempRacio=TempRacio;
                TPosition=i;
                PossibleItem=true;
            }
        }
        if (PossibleItem){
            MaxProfit+=profits[TPosition];
            maxWeight-=weights[TPosition];
            usedWeight+=weights[TPosition];
            usedItems[TPosition]=true;
            PossibleItem=false;
        }
        else {flag=true;}
    }
    return MaxProfit;
}










#endif //GREEDY_H
