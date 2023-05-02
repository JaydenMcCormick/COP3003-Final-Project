//---------------------------------------------------------
// File : FinalHeader.h
// Class: COP 3003, Spring 2023
// Devel: Jayden McCormick
// Desc : Contains declarations and constants for
//        the management system.
//---------------------------------------------------------
#ifndef FINAL_FINALHEADER_H
#define FINAL_FINALHEADER_H

#include <iomanip> // filling and manipulating lines in inventory system
#include <vector> // storing lines for inventory system
#include <fstream> // communicating with files for inventory
#include <iostream> // console input/output
#include <string> // asking questions
#include "FileManip.h" // manipulating inventory file
#include <algorithm> // manipulating strings for easier comparisons

// Constants
const int SAZON_OZ = 18;
const int TAJIN_OZ = 14;
const int MIGUELITO_OZ = 35;
const int LPOLVO_OZ = 7;
const int CAYENNE_OZ = 16;
const int CHAMOY_OZ = 33;
const int PSUGAR_OZ = 112;
// floats for changing amounts of spices when buying/using
//---------------------------------------------------------
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
//---------------------------------------------------------
const int GUMMYBEARS_USD = 1198;
const int SKITTLES_USD = 798;
const int GUSHERS_USD = 1279;
const int JRANCHERS_USD = 1464;
const int NERDCLUSTERS_USD = 998;
const int PEACHRINGS_USD = 1616;
const int SWEDISHFISH_USD = 577;
const int STARBURSTS_USD = 798;
// USD (cents) for when buying candy

// Function Declarations
void welcomeMenu(); // displays "CANDY INVENTORY WELCOME"
int generalPrompt(); // prompt for if candy was sold, made, or bought
void whatHappened(int); // takes a number representing if candy is made or sold
bool askBoolean(std::string, std::string); // used for yes/no questions
void addProduct(std::string); // question, how many materials bought
void useProduct(std::string); // question, how much used to make candy
void soldCandy(std::string); // question, what was sold
void dispSpiceUsed(int); // amount of bags made

#endif //FINAL_FINALHEADER_H
