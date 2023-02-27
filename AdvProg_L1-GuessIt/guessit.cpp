Skip to content
Search or jump to…
Pull requests
Issues
Codespaces
Marketplace
Explore
 
@vuniem131104 
wizardap
/
AdvProg_AY2223
Public
forked from csuet/AdvProg_AY2223
Fork your own copy of wizardap/AdvProg_AY2223
Code
Pull requests
Actions
Projects
Security
Insights
AdvProg_AY2223/AdvProg_L1-GuessIt/guessit.cpp
@wizardap
wizardap Well done
Latest commit f60c7a3 3 weeks ago
 History
 2 contributors
@wizardap@csuet
121 lines (99 sloc)  2.79 KB

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
    return 1 + rand() % (100);
}


/***
    Args:
    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number
    int number;
    cout << "Enter your guess(1..100):";
    cin >> number;
    return number;
}


/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber) {
    /***
        TODO: check number with randomNumber and return the result.
              If number is higher than randomNumber, the answer is "Your number is higher."
              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
    string answer;
    if (number > randomNumber) answer = "Your number is higher.";
    else if (number < randomNumber) answer = "Your number is lower.";
    else answer = "Congratulation! You win.";
    return answer;
}


/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong
    if (answer == "Congratulation! You win.") return true;
    else return false;
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
    if (isContinued == 'Y' || isContinued=='y') result=true;
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
    cout << "Do you wanna continue this game ? (Y/N) : ";
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
Footer
© 2023 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
AdvProg_AY2223/guessit.cpp at master · wizardap/AdvProg_AY2223