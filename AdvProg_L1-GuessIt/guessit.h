#ifndef _GUESSIT_H
#define _GUESSIT_H

#include <iostream>
#include <string>
#include <cmath>

int generateRandomNumber();
int getPlayerGuess();
std::string getAnswer(int number, int randomNumber);
bool checkSuccess(std::string answer);
bool checkContinuePlaying(char isContinued);
char getPlayerOpinion();
void playGuessIt();
int run();

#endif