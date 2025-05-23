#ifndef GREEDY_METHOD_H
#define GREEDY_METHOD_H

#include <cmath>
#include <math.h>
#include <bitset>
#include <iostream>

#include "Pallet.h"
#include <iostream>
#include <map>
#include <vector>


unsigned int knapsackGreedyRacio(const std::vector<int> &profits,const std::vector<int> &weights, unsigned int n, unsigned int maxWeight, std::vector<bool> &usedItems,unsigned int &usedWeight) {
    int MaxProfit=0;
    usedWeight=0;
    bool flag=false;
    bool PossibleItem=false;
    for(int i=0;i<n;i++) {usedItems[i]=false;}
    while (!flag) {
        double MaxTempRacio=0.0;
        int TPosition = -1; //start the TPosition wih an invalid value (which will be updated later)
        for (int i=0; i<n; i++) {
            double TempRacio =static_cast<double>(profits[i])/weights[i];
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

unsigned int knapsackGreedyProfit(const std::vector<int> &profits,const std::vector<int> &weights, unsigned int n, unsigned int maxWeight, std::vector<bool> &usedItems,unsigned int &usedWeight) {
    int MaxProfit=0;
    usedWeight=0;
    bool flag=false;
    bool PossibleItem=false;
    for(int i=0;i<n;i++) {usedItems[i]=false;}
    while (!flag) {
        int maxTProfit=0;
        int TPosition = -1;
        for (int i=0; i<n; i++) {
            if (((profits[i]==maxTProfit && weights[i]<weights[TPosition])||profits[i]>maxTProfit) && weights[i]<=maxWeight && usedItems[i]==false) {
                maxTProfit=profits[i];
                TPosition=i;
                PossibleItem=true;
            }
        }
        if (PossibleItem){
            MaxProfit+=maxTProfit;
            maxWeight-=weights[TPosition];
            usedWeight+=weights[TPosition];
            usedItems[TPosition]=true;
            PossibleItem=false;
        }
        else {flag=true;}
    }
    return MaxProfit;
}

unsigned int knapsackGreedyOptimal(const std::vector<int> &profits,const std::vector<int> &weights, unsigned int n, unsigned int maxWeight, std::vector<bool> &usedItems,unsigned int &usedWeight){
    unsigned int usedWeight1 = 0;
    unsigned int usedWeight2 = 0;
    std::vector<bool> usedItems1(n,false);
    std::vector<bool> usedItems2(n,false);
    unsigned int result1 = knapsackGreedyProfit(profits,weights,n,maxWeight,usedItems1,usedWeight1);
    unsigned int result2 = knapsackGreedyRacio(profits,weights,n,maxWeight,usedItems2,usedWeight2);
    if (result1>result2){
        usedWeight=usedWeight1;
        usedItems=usedItems1;
        return result1;
    }
    else{
        usedWeight=usedWeight2;
        usedItems=usedItems2;
        return result2;
    }
}

#endif //GREEDY_METHOD_H
