//
// Created by gustavo-louren-o on 5/20/25.
//

#ifndef WRITE_OUTPUT_H
#define WRITE_OUTPUT_H
#include <string>
#include <vector>
#include <iostream>


inline void write_output(std::vector<int> &weights, std::vector<int> &profits, const std::string& algo, 
                        const std::string& dataset, std::vector<bool> &usedItems, const double executionTime, 
                        const unsigned int maxValue, unsigned int usedWeight) {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "              Output Result             " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "For the algorithm " << algo << " and Dataset: " << dataset << " the results were: " << std::endl;
    std::cout << "Used Items:" << std::endl;
    
    for (int i = 0; i < usedItems.size(); i++) {
        if (usedItems[i] == true) {
            std::cout << "  Item used: " << i + 1 << " With weight: " << weights[i] 
                      << " and profit: " << profits[i] << std::endl;
        }
    }
    
    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "The result of MaximumProfit was: " << maxValue << std::endl;
    std::cout << "The used total weight was: " << usedWeight << std::endl;
    std::cout << "The execution time was: " << executionTime << " milliseconds!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

}

#endif //WRITE_OUTPUT_H
