//---------------------------------------------------------
// File : FileManip.h
// Class: COP 3003, Spring 2023
// Devel: Jayden McCormick
// Desc : Contains function declarations for the
//        file manipulation portion of the system.
//---------------------------------------------------------
#ifndef FINAL_FILEMANIP_H
#define FINAL_FILEMANIP_H
#include "FinalHeader.h"
//---------------------------------------------------------
using std::string;
class Inventory {
private:
    std::fstream invFile;
    std::vector<string> lines;
    std::vector<string> updatedInv;
public:
    Inventory()=default;

    void appendMoneyEarned(std::string fileName, float moneyEarned); // tallies money earned from selling
    void appendMoneySpent(std::string fileName, float moneySpent); //  tallies money spent on supplies
    void updateInventoryBought(std::string fileName, int lineNumber, int amountBought); // updates inventory
                                                                                        // when buying supplies
    void updateInventoryUsed(std::string fileName, int lineNumber, int amountUsed); // updates inventory
                                                                                    // when using supplies
};

#endif //FINAL_FILEMANIP_H
