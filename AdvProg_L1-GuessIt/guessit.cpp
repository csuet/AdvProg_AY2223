#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


int generateRandomNumber() {
    return rand() % 100 + 1;
    
}



int getPlayerGuess() {
    int number;
    cin >> number;
    return number;
}



string getAnswer(int number, int randomNumber) {
    string answer;
    if (number > randomNumber) {
        answer = "Your number is higher.";
    }
    else if (number < randomNumber){
        answer = "Your number is lower.";
    }
    else answer = "Congratulation! You win.";
    return answer;
}



bool checkSuccess(string answer) {
    // TODO: return the result after checE king that player guessed right or wrong
    if (answer != "Congratulation! You win.") return false;
    return true;
}



bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result;
    if (isContinued == 'Y' || isContinued == 'y') result = true;
    return result;
}



char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    cout << "Do you want to continue playing? Y or N." << endl;
    char input;
    cin >> input;
    return input;
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


