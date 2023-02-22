#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


/***
    Args:
        
    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    int number = rand() % 100 + 1;
    return number;
}


/***
    Args:
        
    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    int num;
    cout << "Please enter the number: ";
    cin >> num;
    return num;
}


/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber) {
    string answer;
    if (number > randomNumber) {
        answer = "Your number is higher.";
    }
    else if (number < randomNumber) {
        answer = "Your number is lower.";
    }
    else if (number == randomNumber) {
        answer = "Congratulation! You win.";
    }
    return answer;
}




/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer) {
    if (answer == "Your number is higher.") 
        return false;
    else if (answer == "Your number is lower.")
        return false;
    else
        return true;
}


/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    bool result = false;
    if (isContinued == 'y') {
        result = true;;
    }
    else if (isContinued == 'n')
        result = false;
    return result;
}



/***
    Args:
        
    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    char isContinued;
    cout << "Want to continue ? (y for yes & n for no) ";
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
