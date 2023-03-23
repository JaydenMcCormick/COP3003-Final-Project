//---------------------------------------------------------
// File : FinalHeader.h
// Class: COP 3003, Spring 2023
// Devel: Jayden McCormick
// Desc : Contains declarations and constants for
//        the management system.
//---------------------------------------------------------
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

#endif //FINAL_FINALHEADER_H
