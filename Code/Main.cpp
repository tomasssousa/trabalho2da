#include <iostream>
#include "Menu.h"

int main() {
    while (true) {
        displayIntroMenu();
        int choice;
        std::cout << "What is your choice? " << std::endl;
        std::cin >> choice;
        handleMainMenuChoice(choice);
    }
    return 0;
}