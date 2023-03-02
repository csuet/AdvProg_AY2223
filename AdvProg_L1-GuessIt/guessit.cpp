#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"
#include <bits/stdc++.h>

using namespace std;


/***
    Args:
        
    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    int a;
    srand (time(0));
    a = rand() % 100 + 1;
    return a;
}


/***
    Args:
        
    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    int number;
    cout << endl << "Enter your number between 1 and 100: ";
    cin >> number;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cin >> number;
    }
    if (number > 100 || number <= 0)
    {
    	return number;
    }
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
    if (number > 100 || number <= 0) {
        answer = "Invalid number, guess again.";}
	else if (number > randomNumber) {
        answer = "Your number is higher.";
    } else if (number < randomNumber) {
        answer = "Your number is lower.";
    } else {
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
    if (answer == "Congratulation! You win.")
    {return true;}
    return false;
}


/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;
    if (isContinued == 'y' || isContinued == 'Y')
    {
        result = true;
    }

    return result;
}


/***
    Args:
        
    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
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
