#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


int generateRandomNumber() {
    return rand() % 100 + 1;
}

int getPlayerGuess() {
    int guess; cin >> guess;
    return guess;
}

string getAnswer(int number, int randomNumber) {
    if (number > randomNumber) {return "Your number is higher.";}
    if (number < randomNumber) {return "Your number is lower.";}
    return  "Congratulation! You win.";
}


bool checkSuccess(string answer) {
    if (answer== "Congratulation! You win.") return true;
    return false;
}


bool checkContinuePlaying(char isContinued) {
   if (isContinued=='y' || isContinued== 'Y') return true;
   return false;
}



char getPlayerOpinion() {
    char isContinued;
    cin >> isContinued;
    return isContinued;
}


void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;

    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
