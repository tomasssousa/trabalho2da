//
// Created by gustavo-louren-o on 5/12/25.
//

#include "Menu.h"
#include <iostream>

enum MainMenuChoices {
    LOAD_AND_PARSE = 1,
    DISPLAY_INFO,
    PLAN_ROUTE,
    MENU_INPUT,
    EXECUTE_BATCH_MODE,
    ABOUT,
    EXIT
};


/**
 * @brief Displays the introductory menu with different options for the user.
 *
 * This function outputs a structured and visually clear menu to the console.
 * The menu provides information about the options available in the program,
 * including loading files, displaying map information, route planning, and more.
 * The menu also serves as an entry point for the user to interact with the application.
 */


void displayIntroMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "          Welcome to our project!     " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Load and Parse the given files " << std::endl;
    std::cout << "2. Display the information about the Pallets" << std::endl;
    std::cout << "3. Choose your algorithm (after choosing this option you will be sent to another menu)" << std::endl;
    std::cout << "4. Give Input in Menu" << std::endl;
    std::cout << "5. About" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void handleMainMenuChoice(const int choice) {

}
