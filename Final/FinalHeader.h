#ifndef FINAL_FINALHEADER_H
#define FINAL_FINALHEADER_H
#include <iostream> // console input/output
#include <string> // asking questions
#include "json.hpp"

using json = nlohmann::json;
//---------------------------------------------------------
// Constants
const float SAZON_OZ = 17.6;
const float TAJIN_OZ = 14.0;
const float MIGUELITO_OZ = 35.0;
const float LPOLVO_OZ = 7.0;
const float CAYENNE_OZ = 16.0;
const float CHAMOY_OZ = 33.0;
const float PSUGAR_OZ = 112.0;
// floats for changing amounts of spices when buying/using

const int SAZON_USD = 2150;
const int TAJIN_USD = 566;
const int MIGUELITO_USD = 800;
const int LPOLVO_USD = 327;
const int CAYENNE_USD = 728;
const int CHAMOY_USD = 1193;
const int PSUGAR_USD = 584;
// USD (in cents) for when buying spices
//---------------------------------------------------------
const float CANDY_USED = 3.5; // oz of candy used per bag
const float GUMMYBEARS_OZ = 72.0;
const float SKITTLES_OZ = 54.0;
const float GUSHERS_OZ = 33.6;
const float JRANCHERS_OZ = 60.0;
const float NERDCLUSTERS_OZ = 32.0;
const float PEACHRINGS_OZ = 60.0;
const float SWEDISHFISH_OZ = 28.8;
const float STARBURSTS_OZ = 54.0;
// floats for changing amounts of candy when used and bought

const int GUMMYBEARS_USD = 1198;
const int SKITTLES_USD = 798;
const int GUSHERS_USD = 1279;
const int JRANCHERS_USD = 1464;
const int NERDCLUSTERS_USD = 998;
const int PEACHRINGS_USD = 1616;
const int SWEDISHFISH_USD = 577;
const int STARBURSTS_USD = 798;
// USD (cents) for when buying candy

const int SELLPRICE = 450; // each bag is sold for 450 cents

//---------------------------------------------------------
// Function Declarations
void welcomeMenu(); // displays "CANDY INVENTORY WELCOME"
int generalPrompt(); // prompt for if candy was sold, made, or bought
int whatHappened(int); // int taking a number representing if candy is made or sold
bool askBoolean(std::string, std::string); // used for yes/no questions
long addProduct(std::string); // question, how much materials bought
void useProduct(std::string); // question, how much used to make candy
void soldCandy(std::string); // question, what was sold
void dispSpiceUsed(int); // amount of bags made

//---------------------------------------------------------
// Function Definitions
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
} // End welcomeMenu, used just to display a welcome in ASCII art

/**
 * Initial prompt for if the user bought or used products, or if they sold candy
 * @return
 */
int generalPrompt(){
    int initialChoice;
    //std::cout << "Did you (1) buy or (2) use products or (3) sell candy? \n";
    std::cout << "Enter one of the following, did you: \n"
                 "[1] - Buy Candy\n"
                 "[2] - Make Candy\n"
                 "[3] - Sell Candy\n";
    std::cin >> initialChoice;
    std::cout << "=======================================================================================\n";
    return initialChoice;
} // End generalPrompt

/**
 * Gets what the user enters, buy/use/sell, does what's needed and loops until asked to break.
 * @param whatOccurred
 * @return
 */
int whatHappened(int whatOccurred){
    if (whatOccurred == 1){
        addProduct("Did you buy candy or spice?\n");

    }
    else if(whatOccurred == 2){
        useProduct("What kind of candy did you make?\n");

    }
    else if (whatOccurred == 3){
        soldCandy("What kind of candy did you sell?\n");

    }
    else{
        std::cout << "You entered an invalid response, please retry.";
        exit(-1);
    }
    while (askBoolean("Do you need to enter more options? (Y/N)","Y")) {
        std::cout << "Enter one of the following, did you: \n"
                     "[1] - Buy Candy\n"
                     "[2] - Make Candy\n"
                     "[3] - Sell Candy\n";
        std::cin >> whatOccurred;
        if (whatOccurred == 1){
            addProduct("Did you buy candy or spice?\n");

        }
        else if(whatOccurred == 2){
            useProduct("What kind of candy did you make?\n"
                       "(Refer to multi-worded candies as the first word. Ex: For 'Gummy Bears' type 'Gummy' or 'Nerd Clusters' as 'Nerd'.\n");

        }
        else if (whatOccurred == 3){
            soldCandy("What kind of candy did you sell?\n"
                      "(Refer to multi-worded candies as the first word. Ex: For 'Gummy Bears' type 'Gummy' or 'Nerd Clusters' as 'Nerd'.\n");

        }
        else{
            std::cout << "You entered an invalid response, please retry.";
            exit(-1);
        }
    }

} //End whatHappened

/**
 * Takes a question, and the option to continue and proposes the question
 * looking for the given continueOption
 * @param question
 * @param continueOption
 * @return
 */
bool askBoolean(std::string question, std::string continueOption){
    std::string choice;
    std::cout << question;
    std::cin >> choice;
    if(std::toupper(choice[0]) == continueOption[0]){
        return true;
    }
    return false;
} // End askBoolean

long addProduct(std::string question){
    std::cin.ignore(1,'\n');
    std::string answerQuestion;
    std::string candyAnswer;
    std::string spiceAnswer;
    int amount;
    long totalPrice;

    std::cout << question;
    std::getline(std::cin, answerQuestion);

    if(answerQuestion.find("candy") == 0 || answerQuestion.find("Candy") == 0 || answerQuestion.find("CANDY") == 0){
        std::cout << "What kind of candy did you buy?\n"
                     "(Refer to multi-worded candies as the first word. Ex: For 'Gummy Bears' type 'Gummy' or 'Nerd Clusters' as 'Nerd'.\n";

        std::getline(std::cin, candyAnswer);
        if(candyAnswer.find("gummy") == 0 || candyAnswer.find("Gummy") == 0 || candyAnswer.find("GUMMY") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * GUMMYBEARS_USD;
            std::cout << "You've spent: $" << totalPrice/100;


        }
        else if(candyAnswer.find("skittles") == 0 || candyAnswer.find("Skittles") == 0 || candyAnswer.find("SKITTLES") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * SKITTLES_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(candyAnswer.find("gushers") == 0 || candyAnswer.find("Gushers") == 0 || candyAnswer.find("GUSHERS") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * GUSHERS_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(candyAnswer.find("jolly") == 0 || candyAnswer.find("Jolly") == 0 || candyAnswer.find("JOLLY") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * JRANCHERS_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(candyAnswer.find("nerd") == 0 || candyAnswer.find("Nerd") == 0 || candyAnswer.find("NERD") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * NERDCLUSTERS_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(candyAnswer.find("Peach") == 0 || candyAnswer.find("peach") == 0 || candyAnswer.find("PEACH") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * PEACHRINGS_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(candyAnswer.find("swedish") == 0 || candyAnswer.find("Swedish") == 0 || candyAnswer.find("SWEDISH") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * SWEDISHFISH_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(candyAnswer.find("starbursts") == 0 || candyAnswer.find("Starbursts") == 0 || candyAnswer.find("STARBURSTS") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * STARBURSTS_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else{
            std::cout << "You entered an invalid response, please retry.\n";
            exit(-1);
        }
    }
    else if(answerQuestion.find("spice") == 0 || answerQuestion.find("Spice") == 0 || answerQuestion.find("SPICE") == 0){
        std::cout << "What kind of spice did you buy?\n"
                     "(Refer to multi-worded spices as the first word. Ex: For 'Lucas Polvo' type 'Lucas' or 'Powdered Sugar' as 'Powdered'\n";
        std::getline(std::cin, spiceAnswer);
        if(spiceAnswer.find("sazon") == 0 || spiceAnswer.find("Sazon") == 0 || spiceAnswer.find("SAZON") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * SAZON_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(spiceAnswer.find("tajin") == 0 || spiceAnswer.find("Tajin") == 0 || spiceAnswer.find("TAJIN") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * TAJIN_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(spiceAnswer.find("miguelito") == 0 || spiceAnswer.find("Miguelito") == 0 || spiceAnswer.find("MIGUELITO") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * MIGUELITO_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(spiceAnswer.find("lucas") == 0 || spiceAnswer.find("Lucas") == 0 || spiceAnswer.find("LUCAS") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * LPOLVO_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(spiceAnswer.find("cayenne") == 0 || spiceAnswer.find("Cayenne") == 0 || spiceAnswer.find("CAYENNE") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * CAYENNE_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(spiceAnswer.find("chamoy") == 0 || spiceAnswer.find("Chamoy") == 0 || spiceAnswer.find("CHAMOY") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * CHAMOY_USD;
            std::cout << "You've spent: $" << totalPrice/100;

        }
        else if(spiceAnswer.find("powdered") == 0 || spiceAnswer.find("Powdered") == 0 || spiceAnswer.find("POWDERED") == 0){
            std::cout << "How many containers did you buy?\n";
            std::cin >> amount;
            totalPrice = amount * PSUGAR_USD;
            std::cout << "You've spent: $" << totalPrice/100;

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
    return totalPrice;
} // End addProduct

void useProduct(std::string question){
    std::cin.ignore(1,'\n');
    std::string candyAnswer;
    int amount;
    long candyUsed;

    std::cout << question;
    std::getline(std::cin, candyAnswer);
        if(candyAnswer.find("gummy") == 0 || candyAnswer.find("Gummy") == 0 || candyAnswer.find("GUMMY") == 0){
            std::cout << "How many bags of candy did you make?\n";
            std::cin >> amount;
            candyUsed = amount * CANDY_USED;
            dispSpiceUsed(amount);
            std::cout << "You also used " << candyUsed << " ounces of Gummy Bears.\n";

        }
        else if(candyAnswer.find("skittles") == 0 || candyAnswer.find("Skittles") == 0 || candyAnswer.find("SKITTLES") == 0){
            std::cout << "How many bags of candy did you make?\n";
            std::cin >> amount;
            candyUsed = amount * CANDY_USED;
            dispSpiceUsed(amount);
            std::cout << "You also used " << candyUsed << " ounces of Skittles.\n";
        }
        else if(candyAnswer.find("gushers") == 0 || candyAnswer.find("Gushers") == 0 || candyAnswer.find("GUSHERS") == 0){
            std::cout << "How many bags of candy did you make?\n";
            std::cin >> amount;
            candyUsed = amount * CANDY_USED;
            dispSpiceUsed(amount);
            std::cout << "You also used " << candyUsed << " ounces of Gushers.\n";
        }
        else if(candyAnswer.find("jolly") == 0 || candyAnswer.find("Jolly") == 0 || candyAnswer.find("JOLLY") == 0){
            std::cout << "How many bags of candy did you make?\n";
            std::cin >> amount;
            candyUsed = amount * CANDY_USED;
            dispSpiceUsed(amount);
            std::cout << "You also used " << candyUsed << " ounces of Jolly Ranchers.\n";
        }
        else if(candyAnswer.find("nerd") == 0 || candyAnswer.find("Nerd") == 0 || candyAnswer.find("NERD") == 0){
            std::cout << "How many bags of candy did you make?\n";
            std::cin >> amount;
            candyUsed = amount * CANDY_USED;
            dispSpiceUsed(amount);
            std::cout << "You also used " << candyUsed << " ounces of Nerd Clusters.\n";
        }
        else if(candyAnswer.find("Peach") == 0 || candyAnswer.find("peach") == 0 || candyAnswer.find("PEACH") == 0){
            std::cout << "How many bags of candy did you make?\n";
            std::cin >> amount;
            candyUsed = amount * CANDY_USED;
            dispSpiceUsed(amount);
            std::cout << "You also used " << candyUsed << " ounces of Peach Rings.\n";
        }
        else if(candyAnswer.find("swedish") == 0 || candyAnswer.find("Swedish") == 0 || candyAnswer.find("SWEDISH") == 0){
            std::cout << "How many bags of candy did you make?\n";
            std::cin >> amount;
            candyUsed = amount * CANDY_USED;
            dispSpiceUsed(amount);
            std::cout << "You also used " << candyUsed << " ounces of Swedish Fish.\n";
        }
        else if(candyAnswer.find("starbursts") == 0 || candyAnswer.find("Starbursts") == 0 || candyAnswer.find("STARBURSTS") == 0){
            std::cout << "How many bags of candy did you make?\n";
            std::cin >> amount;
            candyUsed = amount * CANDY_USED;
            dispSpiceUsed(amount);
            std::cout << "You also used " << candyUsed << " ounces of Starbursts.\n";
        }
        else{
            std::cout << "You entered an invalid response, please retry.\n";
            exit(-1);
        }
} // End useProduct

void soldCandy(std::string question){
    std::cin.ignore(1,'\n');
    std::string candyAnswer;
    int amount;
    long totalEarned;

    std::cout << question;
    std::getline(std::cin, candyAnswer);
    if(candyAnswer.find("gummy") == 0 || candyAnswer.find("Gummy") == 0 || candyAnswer.find("GUMMY") == 0){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * GUMMYBEARS_USD;
        std::cout << "You made $" << totalEarned/100 << " from the Gummy Bears.\n";
    }
    else if(candyAnswer.find("skittles") == 0 || candyAnswer.find("Skittles") == 0 || candyAnswer.find("SKITTLES") == 0){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * SKITTLES_USD;
        std::cout << "You made $" << totalEarned/100 << " from the Skittles.\n";
    }
    else if(candyAnswer.find("gushers") == 0 || candyAnswer.find("Gushers") == 0 || candyAnswer.find("GUSHERS") == 0){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * GUSHERS_USD;
        std::cout << "You made $" << totalEarned/100 << " from the Gushers.\n";
    }
    else if(candyAnswer.find("jolly") == 0 || candyAnswer.find("Jolly") == 0 || candyAnswer.find("JOLLY") == 0){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * JRANCHERS_USD;
        std::cout << "You made $" << totalEarned/100 << " from the Jolly Ranchers.\n";
    }
    else if(candyAnswer.find("nerd") == 0 || candyAnswer.find("Nerd") == 0 || candyAnswer.find("NERD") == 0){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * NERDCLUSTERS_USD;
        std::cout << "You made $" << totalEarned/100 << " from the Nerd Clusters.\n";
    }
    else if(candyAnswer.find("Peach") == 0 || candyAnswer.find("peach") == 0 || candyAnswer.find("PEACH") == 0){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * PEACHRINGS_USD;
        std::cout << "You made $" << totalEarned/100 << " from the Peach Rings.\n";
    }
    else if(candyAnswer.find("swedish") == 0 || candyAnswer.find("Swedish") == 0 || candyAnswer.find("SWEDISH") == 0){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * SWEDISHFISH_USD;
        std::cout << "You made $" << totalEarned/100 << " from the Swedish Fish.\n";
    }
    else if(candyAnswer.find("starbursts") == 0 || candyAnswer.find("Starbursts") == 0 || candyAnswer.find("STARBURSTS") == 0){
        std::cout << "How many bags of candy did you sell?\n";
        std::cin >> amount;
        totalEarned = amount * STARBURSTS_USD;
        std::cout << "You made $" << totalEarned/100 << " from the Starbursts.\n";
    }
    else{
        std::cout << "You entered an invalid response, please retry.\n";
        exit(-1);
    }
} // End candySold

void dispSpiceUsed(int amount) {
    double sazonAmt, tajinAmt, lpolvoAmt, miguelitoAmt, cayenneAmt, chamoyAmt, psugarAmt;
    sazonAmt = SAZON_OZ*amount;
    tajinAmt = TAJIN_OZ*amount;
    miguelitoAmt = MIGUELITO_OZ*amount;
    lpolvoAmt = LPOLVO_OZ*amount;
    cayenneAmt = CAYENNE_OZ*amount;
    chamoyAmt = CHAMOY_OZ*amount;
    std::cout << "In ounces, you used the following amounts of each spice: \n"
                 "Sazon: " << sazonAmt << ", Tajin: " << tajinAmt << ", Miguelito: " << miguelitoAmt << ", Lucas Polvo: " << lpolvoAmt<< ",\n"
                 "Cayenne Pepper: " << cayenneAmt << ", and Chamoy: " << chamoyAmt << ".\n";
}


//---------------------------------------------------------
#endif //FINAL_FINALHEADER_H
