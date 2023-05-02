//---------------------------------------------------------
// File : FileManip.cpp
// Class: COP 3003, Spring 2023
// Devel: Jayden McCormick
// Desc : Contains function definitions for the
//        file manipulation portion of the system.
//---------------------------------------------------------
#include "FileManip.h"
//---------------------------------------------------------
/**
 * Used to keep track of money earned, adds a line to a
 * file with every entered sale.
 * Takes the name of the file to update, and
 * the amount of money gained from the transaction.
 * @param fileName
 * @param moneyEarned
 */
void Inventory::appendMoneyEarned(std::string fileName, float moneyEarned) {
    std::ofstream outFile;
    outFile.open(fileName, std::ios_base::app);
    if (outFile.is_open()) {
        outFile << moneyEarned << "\n";
        outFile.close();
    }
    else {
        std::cout << "An error occurred writing the money earned.\n";
    }
}// end appendMoneyEarned

/**
 * Used to keep track of money spent, adds a line to a
 * file with every entered sale.
 * Takes the name of the file to update, and
 * the amount of money gained from the transaction.
 * @param fileName
 * @param moneySpent
 */
void Inventory::appendMoneySpent(std::string fileName, float moneySpent) {
    std::ofstream outFile;
    outFile.open(fileName, std::ios_base::app); // Open file in append mode
    if (outFile.is_open()) {
        outFile << moneySpent << "\n";
        outFile.close();
    }
    else {
        std::cout << "An error occurred writing the money spent.\n";
    }
}// end appendMoneySpent

/**
 * Used to update inventory text file when buying items
 * Takes the file name to update, the line number of the ingredient bought and
 * the amount of the ingredient bought.
 * @param fileName
 * @param lineNumber
 * @param amountBought
 */
void Inventory::updateInventoryBought(std::string fileName, int lineNumber, int amountBought) {
    int currentValue = 0;
    std::fstream invFile(fileName, std::ios::in | std::ios::out);
    invFile.seekg((lineNumber-1)*3, std::ios::beg); // Move file pointer to the beginning
    invFile >> currentValue;
    currentValue += amountBought;
    invFile.seekp((lineNumber-1)*3, std::ios::beg); // Move file pointer to the beginning

    invFile << currentValue;
    invFile.close();
}// end updateInventoryBought

/**
 * Used to update inventory text file when making candy(using ingredients)
 * Takes the file name to update, the line number of the ingredient bought and
 * the amount of the ingredient bought.
 * @param fileName
 * @param lineNumber
 * @param amountUsed
 */

void Inventory::updateInventoryUsed(std::string fileName, int lineNumber, int amountUsed) {
    int currentValue = 0;
    std::fstream invFile(fileName, std::ios::in | std::ios::out);
    invFile.seekg((lineNumber-1)*3, std::ios::beg); // Move file pointer to the beginning
    invFile >> currentValue;
    currentValue -= amountUsed;
    invFile.seekp((lineNumber-1)*3, std::ios::beg); // Move file pointer to the beginning

    invFile << currentValue;
    invFile.close();
}// end updateInventoryUsed