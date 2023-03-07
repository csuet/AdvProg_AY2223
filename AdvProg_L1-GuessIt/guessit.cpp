#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


int generateRandomNumber() {
    srand(time(NULL));
    int randomNumber = rand() % 100 + 1;
    return randomNumber;
}


int getPlayerGuess() {
    cout << "PlayerGuess: ";
    int x; cin >> x;
    return x;
}


string getAnswer(int number, int randomNumber) {
    string answer;
    if(number > randomNumber) 
    {
        answer = "Your number is higher.";
    }
    else if(number > randomNumber) 
    {
        answer = "Your number is lower.";
    }
    else {
        answer = "Congratulation! You win.";
    }
    return answer;
}


bool checkSuccess(string answer) {
    if(answer == "Congratulation! You win.") {
        return true;
    }
    else {
        return false;
    }
}


bool checkContinuePlaying(char isContinued) {
    return (isContinued == "Y" || isContinued == "y");
}


char getPlayerOpinion() {
    char isContinued;
    cout << "Continue playing ?(Y/N)\n";
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
