//
// Created by gustavo-louren-o on 5/12/25.
//

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

void displayIntroMenu();

void displayAboutMenu();

void displayDatasetsOptions();

void handleMainMenuChoice(int choice);

void handle_csv(int &capacity, int &numPallets, std::vector<int> &weights, std::vector<int> &profits, const std::string &filename_truck,const std::string &filename_pallet);



#endif //MENU_H
