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
<<<<<<< HEAD
    cout << "PlayerGuess: ";
    int x; cin >> x;
    return x;
=======
    // TODO: Ask the player guest and return the player's number
    cout << "Enter your guess: ";
    int guess; cin >> guess;
    return 1;
>>>>>>> 7e1e40f66b65971f186785a19819915f818db57a
}


string getAnswer(int number, int randomNumber) {
    string answer;
<<<<<<< HEAD
    if(number > randomNumber) 
    {
        answer = "Your number is higher.";
    }
    else if(number > randomNumber) 
    {
=======
    if(number > randomNumber) {
        answer = "Your number is higher.";
    }
    else if(number < randomNumber) {
>>>>>>> 7e1e40f66b65971f186785a19819915f818db57a
        answer = "Your number is lower.";
    }
    else {
        answer = "Congratulation! You win.";
    }
    return answer;
}


bool checkSuccess(string answer) {
<<<<<<< HEAD
    if(answer == "Congratulation! You win.") {
        return true;
    }
    else {
        return false;
    }
=======
    // TODO: return the result after checking that player guessed right or wrong
    if(answer != "Congratulation! You win.") return false;
    return true;
>>>>>>> 7e1e40f66b65971f186785a19819915f818db57a
}


bool checkContinuePlaying(char isContinued) {
<<<<<<< HEAD
    return (isContinued == "Y" || isContinued == "y");
=======
    // TODO: return result after checking player continue playing or not
    bool result = false;
    return result;
>>>>>>> 7e1e40f66b65971f186785a19819915f818db57a
}


char getPlayerOpinion() {
<<<<<<< HEAD
    char isContinued;
    cout << "Continue playing ?(Y/N)\n";
=======
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued; 
    cout << "Continue playing?" << endl;
>>>>>>> 7e1e40f66b65971f186785a19819915f818db57a
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
