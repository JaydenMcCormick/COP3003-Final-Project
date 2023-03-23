//---------------------------------------------------------
// File : FinalProject.cpp
// Class: COP 3003, Spring 2023
// Devel: Jayden McCormick
// Desc : Inventory system for a candy business, calculating
//        expiration date and more.
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

//---------------------------------------------------------

/* ---- Ignore ----
 *
 * Pseudocode
 * prompt user for if they are buying or using their supplies, or for candy sold /-/
 *
 * if bought:
 * use a loop to ask (one thing at a time) {if a spice or a candy was bought
 * what spice / candy
 * how many containers
 * add amount to inventory, add money spent to totalcost}
 * update inventory, money spent on trip, total spent
 *
 * if used:
 * loop asking {what candy used, how many batches
 * ask current date
 * use constants to subtract the candy used and spice amounts from inv
 * using gotten numbers, add made candy to inventory and give an expiration date}
 * update inventory(candy used, candy bags made), expiration date,
 *
 * if sold:
 * ask what color sticker, and how many bags were sold
 * multiply bags sold by SELLPRICE for raw money earned
 * multiply inputted number by cost per assembled (matching sticker) for spent
 * subtract raw money from spent to get profit and += totalprofit
 * update inventory, profit for this entry, total profit thus far (don't forget to convert cents to dollars)
 */