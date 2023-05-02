//---------------------------------------------------------
// File : FinalProject.cpp
// Class: COP 3003, Spring 2023
// Devel: Jayden McCormick
// Desc : Inventory system for a candy business.
//        Takes user input for if they made, bought,
//        or sold candy and does necessary calculations
//        and stores inventory data to a text file.
//---------------------------------------------------------
#include <iostream>
#include "FinalHeader.h"
//---------------------------------------------------------
int main() {
    welcomeMenu();
    whatHappened(generalPrompt());

    std::cout << "Thank you for using this software.";
    return 0;
}