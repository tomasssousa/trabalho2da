//
// Created by gustavo-louren-o on 5/20/25.
//
//
// Created by gustavo-louren-o on 5/12/25.
//

#include "Menu.h"

#include <chrono>

#include "readCSV.h"
#include <iostream>
#include <vector>
#include <string>
#include "Brute_Force.h"
#include "Greedy_Method.h"
#include <cmath>
#include "Write_output.h"

std::string algorithm;
int numOfPallets = 0;
int capacity = 0;
std::string ChosenDataSet;
std::string ChosenAlgo;
std::vector<int> weights;
std::vector<int> profits;

enum MainMenuChoices {
    LOAD_AND_PARSE = 1,
    DISPLAY_INFO,
    CHOOSE_ALGO,
    RUN,
    ABOUT,
    EXIT
};

enum DataSetsChoices {
    DATASET1 = 1,
    DATASET2,
    DATASET3,
    DATASET4,
    DATASET_GOBACK
};

enum AlgorithmChoices {
    BRUTE_FORCE = 1,
    DYNAMIC,
    GREEDY,
    INTEGER,
    ALGO_BACK_TO_MAIN
};

enum AboutMenuChoices {
    ABOUT_BACK_TO_MAIN = 1
};

/*Main idea behind the option to choose the Datasets and algorithms, for example use a strin to save the name of the dataset
 * and algorithm
 */

void displayInfo(const std::string& ChosenDataSet,const std::vector<int>& weights, const std::vector<int>& profits, int capacity, int numpallets) {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "          Welcome to the Info Menu     " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "The Data set " << ChosenDataSet << " has: " << std::endl;
    for (const auto weight : weights) {
        std::cout << weight << " ";
    }
    std::cout << "for weights" << std::endl;
    std::cout << "And has the following for profits: " << std::endl;

    for (const auto profit : profits) {
        std::cout << profit << " ";
    }
    std::cout << std::endl;
    std::cout << "And capacity " << capacity << std::endl;
    std::cout << "And " << numpallets << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1.Go Back to Main Menu" << std::endl;

}


/**
 * @brief Displays the introductory menu with different options for the user.
 *
 * This function outputs a structured and visually clear menu to the console.
 * The menu provides information about the options available in the program,
 * including loading files, displaying map information, route planning, and more.
 * The menu also serves as an entry point for the user to interact with the application.
 */

void handle_csv(int &capacity, int &numPallets, std::vector<int> &weights, std::vector<int> &profits, const std::string &filename_truck,const std::string &filename_pallet) {
    loadTruck(capacity,numPallets,filename_truck);
    loadPallets(weights,profits,filename_pallet);
}



void displayIntroMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "          Welcome to our project!     " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Load and Parse the given files " << std::endl;
    std::cout << "2. Display the information about the Pallets" << std::endl;
    std::cout << "3. Choose your algorithm (after choosing this option you will be sent to another menu)" << std::endl;
    std::cout << "4. Run"<<std::endl;
    std::cout << "5. About" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void displayDatasetsOptions() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "          Data Set Choices     " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "It is provided 4 total datasets to read and solve, in this menu";
    std::cout << "you will choose which data set to solve!" << std::endl;
    std::cout << "1.Dataset 1" << std::endl;
    std::cout << "2.Dataset 2" << std::endl;
    std::cout << "3.Dataset 3" << std::endl;
    std::cout << "4.Dataset 4" << std::endl;
    std::cout << "5.Back to Main Menu (preferably after choosing which option to solve)" << std::endl;
}

void chooseAlgorithm() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "          Algorithm Choices     " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Choose which algorithm to solve the problem" << std::endl;
    std::cout << "1.Brute-Force" << std::endl;
    std::cout << "2.Dynamic Programming" << std::endl;
    std::cout << "3.Greedy(weight-profit ratio" << std::endl;
    std::cout << "4.Integer Linear Programming" << std::endl;
    std::cout << "5.Go Back to Main Menu" << std::endl;
}

void displayAboutMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "          Welcome to the About Menu!     " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "This project was done by:" << std::endl;
    std::cout << "  Gustavo Lourenço 202306578" << std::endl;
    std::cout << "  Tomás Sousa 202303524" << std::endl;
    std::cout << "  Gonçalo França 202305533" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Go back to Main Menu" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void handleMainMenuChoice(const int choice) {
    switch (choice) {
        case LOAD_AND_PARSE:
            while (true) {
                displayDatasetsOptions();
                int datasetoption;
                std::cout << "What dataset you want (insert a number between 1 and 4): " << std::endl;
                std::cin >> datasetoption;
                if (datasetoption == DATASET1) {
                    ChosenDataSet = "1";
                    weights.clear();
                    profits.clear();
                    handle_csv(capacity,numOfPallets,weights,profits,"../CSV_Files/Datasets_Project2/datasets/TruckAndPallets_01.csv","../CSV_Files/Datasets_Project2/datasets/Pallets_01.csv");
                } else if (datasetoption == DATASET2) {
                    weights.clear();
                    profits.clear();
                    ChosenDataSet = "2";
                    handle_csv(capacity,numOfPallets,weights,profits,"../CSV_Files/Datasets_Project2/datasets/TruckAndPallets_02.csv","../CSV_Files/Datasets_Project2/datasets/Pallets_02.csv");
                } else if (datasetoption == DATASET3) {
                    ChosenDataSet = "3";
                    weights.clear();
                    profits.clear();
                    handle_csv(capacity,numOfPallets,weights,profits,"../CSV_Files/Datasets_Project2/datasets/TruckAndPallets_03.csv","../CSV_Files/Datasets_Project2/datasets/Pallets_03.csv");
                } else if (datasetoption == DATASET4) {
                    ChosenDataSet = "4";
                    weights.clear();
                    profits.clear();
                    handle_csv(capacity,numOfPallets,weights,profits,"../CSV_Files/Datasets_Project2/datasets/TruckAndPallets_04.csv","../CSV_Files/Datasets_Project2/datasets/Pallets_04.csv");
                } else if (datasetoption == DATASET_GOBACK){
                    break;
                }
            }
            break;
        case DISPLAY_INFO:
            while (true) {
                displayInfo(ChosenDataSet,weights,profits,capacity,numOfPallets);
                int infoChoice;
                std::cout << "Choose your option: " << std::endl;
                std::cin >> infoChoice;
                if (infoChoice == 1) {
                    break;
                }
                std::cout << "Invalid Option" << std::endl;
            }
            break;
        case CHOOSE_ALGO:
            while (true) {
                chooseAlgorithm();
                int algoChoice;
                std::cout << "Choose your algorithm (between 1 and 4)" << std::endl;
                std::cin >> algoChoice;
                if (algoChoice == BRUTE_FORCE) {
                    ChosenAlgo = "Brute Force";
                } else if (algoChoice == DYNAMIC) {
                    ChosenAlgo = "Dynamic Prog";
                } else if (algoChoice == GREEDY) {
                    ChosenAlgo = "Greedy";
                } else if (algoChoice == INTEGER) {
                    ChosenAlgo = "Integer";
                } else if (algoChoice == ALGO_BACK_TO_MAIN) {
                    break;
                }
            }
            break;
        case RUN:
            if (ChosenAlgo == "Brute Force") {
                unsigned int usedWeight = 0;
                std::vector<bool> usedItems(numOfPallets,false);
                auto start = std::chrono::_V2::high_resolution_clock::now();
                int result = knapsackBF(profits,weights,numOfPallets,capacity,usedItems,usedWeight);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double,std::milli> duration = end - start;
                write_output(weights,profits,ChosenAlgo,ChosenDataSet,usedItems,duration.count(),result,usedWeight);
            } else if (ChosenAlgo == "Greedy") {
                unsigned int usedWeight = 0;
                std::vector<bool> usedItems(numOfPallets,false);
                auto start = std::chrono::_V2::high_resolution_clock::now();
                int result = knapsackGreedyRacio(profits,weights,numOfPallets,capacity,usedItems,usedWeight);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double,std::milli> duration = end - start;
                write_output(weights,profits,ChosenAlgo,ChosenDataSet,usedItems,duration.count(),result,usedWeight);
            }

            break;
        default:
            std::cout << "Invalid Choice. Try Again." << std::endl;
    }

}
