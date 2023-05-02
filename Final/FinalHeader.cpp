//---------------------------------------------------------
// File : FinalHeader.cpp
// Class: COP 3003, Spring 2023
// Devel: Jayden McCormick
// Desc : Contains function definitions for the
//        management system.
//---------------------------------------------------------
#include "FinalHeader.h"
//---------------------------------------------------------
// Function Definitions
/**
 *  Used just to display a welcome in ASCII art
 */
void welcomeMenu(){
    std::cout << "   ___  ___  __  __ ____   _  _    __ __  __ __ __  ____ __  __ ______   ___   ____  _  _\n"
                 "  //   // \\\\ ||\\ || || \\\\  \\\\//    || ||\\ || || || ||    ||\\ || | || |  // \\\\  || \\\\ \\\\//\n"
                 " ((    ||=|| ||\\\\|| ||  ))  )/     || ||\\\\|| \\\\ // ||==  ||\\\\||   ||   ((   )) ||_//  )/ \n"
                 "  \\\\__ || || || \\|| ||_//  //      || || \\||  \\V/  ||___ || \\||   ||    \\\\_//  || \\\\ //  \n"
                 "=======================================================================================\n"
                 " __    __  ____ __      ___   ___   ___  ___  ____                                       \n"
                 " ||    || ||    ||     //    // \\\\  ||\\\\//|| ||                                          \n"
                 " \\\\ /\\ // ||==  ||    ((    ((   )) || \\/ || ||==                                        \n"
                 "  \\V/\\V/  ||___ ||__|  \\\\__  \\\\_//  ||    || ||___                                       \n"
                 "                                                                                         \n";
} // End welcomeMenu

/**
 * Initial prompt for if the user bought or used products, or if they sold candy
 * @return initialChoice - returns what they did, buy/use/sell supplies/candy
 */
int generalPrompt(){
    int initialChoice;
    std::cout << "Enter one of the following, did you: \n"
                 "[1] - Buy Supplies\n"
                 "[2] - Sell Candy\n"
                 "[3] - Make Candy\n";
    std::cin >> initialChoice;
    std::cout << "=========================================="
                 "=============================================\n";
    return initialChoice;
} // End generalPrompt

/**
 * Used to get input if user bought, sold, or made candy and redirects to the correct area from there.
 * Gets what the user enters, buy/use/sell, does what's needed and loops until asked to break.
 * Returns
 * @param whatOccurred
 */
void whatHappened(int whatOccurred){
    //directed from generalPrompt(), the if statements respond to it
    if (whatOccurred == 1){
        addProduct("Did you buy candy or spice?\n");
    }
    else if(whatOccurred == 3){
        useProduct("What kind of candy did you make?\n");
    }
    else if (whatOccurred == 2){
        soldCandy("What kind of candy did you sell?\n");
    }
    else{
        std::cout << "You entered an invalid response, please retry.";
        exit(-1);
    }
    //After first entry, loop asking if they need to enter more options.
    while (askBoolean("\nDo you need to enter more options?"
                      " (Y/N)","Y")) {
        std::cout << "Enter one of the following, did you: \n"
                     "[1] - Buy Candy\n"
                     "[2] - Make Candy\n"
                     "[3] - Sell Candy\n";
        std::cin >> whatOccurred;
        if (whatOccurred == 1){
            addProduct("Did you buy candy or spice?\n");
        }
        else if(whatOccurred == 2){
            useProduct("What kind of candy did you make?\n "
                       "(Refer to multi-worded candies as the first word."
                       " Ex: For 'Gummy Bears' type 'Gummy' or 'Nerd Clusters' as 'Nerd'.\n");
        }
        else if (whatOccurred == 3){
            soldCandy("What kind of candy did you sell?\n"
                      "(Refer to multi-worded candies as the first word."
                      " Ex: For 'Gummy Bears' type 'Gummy' or 'Nerd Clusters' as 'Nerd'.\n");
        }
        else{
            std::cout << "You entered an invalid response, please retry.";
            exit(-1);
        }
    }
} //End whatHappened

/**
 * Takes a question, and the option wanted
 * to continue and proposes the question
 * looking for the given continueOption
 * Returns true/false, if they want to continue or not
 * @param question
 * @param continueOption
 * @return
 */
bool askBoolean(std::string question, std::string continueOption){
    //Will be (Y/N) so only need the first letter
    std::cin.clear();
    std::string choice;
    std::cout << question;
    std::cin >> choice;
    //forces uppercase first letter, so doesn't matter if user does either
    if(std::toupper(choice[0]) == continueOption[0]){
        return true;
    }
    return false;
} // End askBoolean

/**
 * Used to change inventory values when the user went out and bought supplies.
 * Takes a question, determines if the user bought candy or spice,
 * @param question
 */
void addProduct(std::string question){
    //clears any cin that may mess with things
    std::cin.ignore(1,'\n');
    std::string answerQuestion, candyAnswer, spiceAnswer;
    int amount;
    long totalPrice, convUSD;
    Inventory currentInv;

    std::cout << question;
    std::getline(std::cin, answerQuestion);

    // Convert the answer to lowercase to simplify the comparison logic
    std::transform(answerQuestion.begin(), answerQuestion.end(),
                   answerQuestion.begin(), ::tolower);

    if (answerQuestion.find("candy") == 0) {
        std::cout << "What kind of candy did you buy?\n"
                  << "(Refer to multi-worded candies as the first word. Ex: For 'Gummy Bears' type 'Gummy' or"
                     " 'Nerd Clusters' as 'Nerd'.\n";
        std::getline(std::cin, candyAnswer);

        std::transform(candyAnswer.begin(), candyAnswer.end(), candyAnswer.begin(), ::tolower);
        if (candyAnswer == "gummy") {
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * GUMMYBEARS_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << totalPrice/100;
            currentInv.updateInventoryBought("inventory.txt", 7, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if (candyAnswer == "skittles") {
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * SKITTLES_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 8, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if (candyAnswer == "gushers") {
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * GUSHERS_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 10, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if (candyAnswer == "jolly") {
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * JRANCHERS_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 11, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if (candyAnswer == "nerd") {
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * NERDCLUSTERS_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 12, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if(candyAnswer == "peach"){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * PEACHRINGS_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 13, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if(candyAnswer == "swedish"){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * SWEDISHFISH_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 14, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if(candyAnswer == "starbursts"){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * STARBURSTS_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 9, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else{
            std::cout << "You entered an invalid response, please retry.\n";
            exit(-1);
        }
    }

    else if(answerQuestion == "spice"){
        std::cout << "What kind of spice did you buy?\n"
                     "(Refer to multi-worded spices as the first word. Ex: For 'Lucas Polvo' type 'Lucas'"
                     " or 'Powdered Sugar' as 'Powdered'\n";
        std::getline(std::cin, spiceAnswer);

        // Convert the answer to lowercase to simplify the comparison logic
        std::transform(spiceAnswer.begin(), spiceAnswer.end(), spiceAnswer.begin(), ::tolower);

        if(spiceAnswer == "sazon"){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * SAZON_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 0, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if(spiceAnswer == "tajin"){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * TAJIN_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 1, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if(spiceAnswer == "miguelito"){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * MIGUELITO_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 2, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if(spiceAnswer == "lucas"){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * LPOLVO_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 3, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if(spiceAnswer == "cayenne"){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * CAYENNE_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 4, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if(spiceAnswer == "chamoy"){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * CHAMOY_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 5, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else if(spiceAnswer == "powdered"){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * PSUGAR_USD;
            convUSD = totalPrice/100;
            std::cout << "You've spent: $" << convUSD;
            currentInv.updateInventoryBought("inventory.txt", 6, amount);
            currentInv.appendMoneySpent("moneyspent.txt", convUSD);
        }
        else{
            std::cout << "You entered an invalid response, please retry.\n";
            exit(-1);
        }
    }
    else{
        std::cout << "You entered an invalid response, please retry.\n";
        exit(-1);
    }
} // End addProduct

/**
 * Used to change inventory values when making candy.
 * Takes a question, asks how much product was made and what candy was made.
 * Calculates spices, and candy amounts used
 * @param question
 */
void useProduct(std::string question){
    // clears cin of anything that may be left over to mess with things
    std::cin.ignore(1,'\n');
    std::string candyAnswer;
    int amount;
    long candyUsed;
    Inventory currentInv;

    std::cout << question << "Remember to refer"
    " to multi-worded candies as the first word. "
    "Ex: For 'Gummy Bears' type 'Gummy' or 'Nerd Clusters' as 'Nerd'.\n";
    std::getline(std::cin, candyAnswer);

    // Convert the candy answer to lowercase to simplify the comparison logic
    std::transform(candyAnswer.begin(), candyAnswer.end(), candyAnswer.begin(), ::tolower);

    if(candyAnswer == "gummy") {
        std::cout << "How many bags of candy did you make?\n";
        std::cin >> amount;
        candyUsed = amount * CANDY_USED;
        dispSpiceUsed(amount);
        currentInv.updateInventoryUsed("inventory.txt", 7, amount);
        std::cout << "You also used " << candyUsed << " ounces of Gummy Bears.\n";
    }
    else if(candyAnswer == "skittles") {
        std::cout << "How many bags of candy did you make?\n";
        std::cin >> amount;
        candyUsed = amount * CANDY_USED;
        dispSpiceUsed(amount);
        currentInv.updateInventoryUsed("inventory.txt",8, amount);
        std::cout << "You also used " << candyUsed << " ounces of Skittles.\n";
    }
    else if(candyAnswer == "gushers") {
        std::cout << "How many bags of candy did you make?\n";
        std::cin >> amount;
        candyUsed = amount * CANDY_USED;
        dispSpiceUsed(amount);
        currentInv.updateInventoryUsed("inventory.txt",10, amount);
        std::cout << "You also used " << candyUsed << " ounces of Gushers.\n";
    }
    else if(candyAnswer == "jolly") {
        std::cout << "How many bags of candy did you make?\n";
        std::cin >> amount;
        candyUsed = amount * CANDY_USED;
        dispSpiceUsed(amount);
        currentInv.updateInventoryUsed("inventory.txt",11, amount);
        std::cout << "You also used " << candyUsed << " ounces of Jolly Ranchers.\n";
    }
    else if(candyAnswer == "nerd") {
        std::cout << "How many bags of candy did you make?\n";
        std::cin >> amount;
        candyUsed = amount * CANDY_USED;
        dispSpiceUsed(amount);
        currentInv.updateInventoryUsed("inventory.txt",12, amount);
        std::cout << "You also used " << candyUsed << " ounces of Nerd Clusters.\n";
    }
    else if(candyAnswer == "peach") {
        std::cout << "How many bags of candy did you make?\n";
        std::cin >> amount;
        candyUsed = amount * CANDY_USED;
        dispSpiceUsed(amount);
        currentInv.updateInventoryUsed("inventory.txt",13, amount);
        std::cout << "You also used " << candyUsed << " ounces of Peach Rings.\n";
    }
    else if(candyAnswer == "swedish") {
        std::cout << "How many bags of candy did you make?\n";
        std::cin >> amount;
        candyUsed = amount * CANDY_USED;
        dispSpiceUsed(amount);
        currentInv.updateInventoryUsed("inventory.txt",14, amount);
        std::cout << "You also used " << candyUsed << " ounces of Swedish Fish.\n";
    }
    else if(candyAnswer == "starburst" || candyAnswer == "starbursts") {
        std::cout << "How many bags of candy did you make?\n";
        std::cin >> amount;
        candyUsed = amount * CANDY_USED;
        dispSpiceUsed(amount);
        currentInv.updateInventoryUsed("inventory.txt",9, amount);
        std::cout << "You also used " << candyUsed << " ounces of Starbursts.\n";
    }
    else{
        std::cout << "You entered an invalid response, please retry.\n";
        exit(-1);
    }
} // End useProduct

/**
 * Used to update inventory and money values when candy is sold.
 * Takes a question, asks what candy was sold, how much and calculates the money earned
 * @param question
 */
void soldCandy(std::string question){
    // clears cin in case anything is left over to mess with things
    std::cin.ignore(1,'\n');
    std::string candyAnswer;
    int amount;
    long totalEarned;
    long convUSD;
    Inventory currentInv;

    std::cout << question << "\nRemember to refer"
    " to multi-worded candies as the first word. "
    "Ex: For 'Gummy Bears' type 'Gummy' or 'Nerd Clusters' as 'Nerd'.\n";
    std::getline(std::cin, candyAnswer);

    // Convert the candy answer to lowercase to simplify the comparison logic
    std::transform(candyAnswer.begin(), candyAnswer.end(), candyAnswer.begin(), ::tolower);

    if(candyAnswer == "gummy"){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * GUMMYBEARS_USD;
        convUSD = totalEarned/100;
        currentInv.appendMoneyEarned("moneygained.txt",convUSD);
        std::cout << "You made $" << convUSD << " from the Gummy Bears.\n";
    }
    else if(candyAnswer == "skittles"){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * SKITTLES_USD;
        convUSD = totalEarned/100;
        currentInv.appendMoneyEarned("moneygained.txt",convUSD);
        std::cout << "You made $" << convUSD << " from the Skittles.\n";
    }
    else if(candyAnswer == "gushers"){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * GUSHERS_USD;
        convUSD = totalEarned/100;
        currentInv.appendMoneyEarned("moneygained.txt",convUSD);
        std::cout << "You made $" << convUSD << " from the Gushers.\n";
    }
    else if(candyAnswer == "jolly"){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * JRANCHERS_USD;
        convUSD = totalEarned/100;
        currentInv.appendMoneyEarned("moneygained.txt",convUSD);
        std::cout << "You made $" << convUSD << " from the Jolly Ranchers.\n";
    }
    else if(candyAnswer == "nerd"){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * NERDCLUSTERS_USD;
        convUSD = totalEarned/100;
        currentInv.appendMoneyEarned("moneygained.txt",convUSD);
        std::cout << "You made $" << convUSD << " from the Nerd Clusters.\n";
    }
    else if(candyAnswer == "peach"){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * PEACHRINGS_USD;
        convUSD = totalEarned/100;
        currentInv.appendMoneyEarned("moneygained.txt",convUSD);
        std::cout << "You made $" << convUSD << " from the Peach Rings.\n";
    }
    else if(candyAnswer == "swedish"){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * SWEDISHFISH_USD;
        convUSD = totalEarned/100;
        currentInv.appendMoneyEarned("moneygained.txt",convUSD);
        std::cout << "You made $" << convUSD << " from the Swedish Fish.\n";
    }
    else if(candyAnswer == "starburst" || candyAnswer == "starbursts"){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * STARBURSTS_USD;
        convUSD = totalEarned/100;
        currentInv.appendMoneyEarned("moneygained.txt",convUSD);
        std::cout << "You made $" << convUSD << " from the Starbursts.\n";
    }
    else{
        std::cout << "You entered an invalid response, please retry.\n";
        exit(-1);
    }
} // End candySold

/**
 * Takes amount of bags of candy made and calculates
 * and displays how much total spice was used
 * also updates inventory with the amounts used.
 * @param amount
 */
void dispSpiceUsed(int amount) {
    double sazonAmt, tajinAmt, lpolvoAmt,
    miguelitoAmt, cayenneAmt, chamoyAmt, psugarAmt;
    Inventory currentInv;
    sazonAmt = SAZON_OZ*amount;
    tajinAmt = TAJIN_OZ*amount;
    miguelitoAmt = MIGUELITO_OZ*amount;
    lpolvoAmt = LPOLVO_OZ*amount;
    cayenneAmt = CAYENNE_OZ*amount;
    chamoyAmt = CHAMOY_OZ*amount;
    psugarAmt = PSUGAR_OZ*amount;
    std::cout << "In ounces, you used the following amounts of each spice: \n"
                 "Sazon: " << sazonAmt << ", Tajin: " << tajinAmt <<
                 ", Miguelito: " << miguelitoAmt << ", Lucas Polvo: " << lpolvoAmt<< ",\n"
                 "Cayenne Pepper: " << cayenneAmt << ", Powdered Sugar: " << psugarAmt <<
                 ", and Chamoy: " << chamoyAmt << ".\n";
    currentInv.updateInventoryUsed("inventory.txt", 0, sazonAmt);
    currentInv.updateInventoryUsed("inventory.txt", 1, tajinAmt);
    currentInv.updateInventoryUsed("inventory.txt", 2, miguelitoAmt);
    currentInv.updateInventoryUsed("inventory.txt", 3, lpolvoAmt);
    currentInv.updateInventoryUsed("inventory.txt", 4, cayenneAmt);
    currentInv.updateInventoryUsed("inventory.txt", 5, chamoyAmt);
    currentInv.updateInventoryUsed("inventory.txt", 6, psugarAmt);
} // End dispSpiceUsed

