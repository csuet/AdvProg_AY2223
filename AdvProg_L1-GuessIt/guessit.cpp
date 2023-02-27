#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

int generateRandomNumber() {
    int n;
    srand(time(NULL));
    n=rand()%100;
    return n;
}

int getPlayerGuess() {
    int n;
    cin>>n;
    return n;
}

string getAnswer(int number, int randomNumber) {
    string answer;
    if (number==randomNumber)
    {
        //cout<<"Congratulation! You win.";
        answer="Congratulation! You win.";
    }
    else if (number>randomNumber)
    {
        //cout<<"Your number is higher.";
        answer="Your number is higher.";
    }
    else if (number<randomNumber)
    {
        answer="Your number is lower.";
    }
    return answer;
}

bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong
    if (answer=="Congratulation! You win.")
    {
        return true;
    }
    return false;
}

bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;
    if (isContinued=='Y'||isContinued=='y'||isContinued=='countinue')
    {
        return true;
    }
    
    return result;
}

char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    //cout<<"continue: ";
    cin>>isContinued;
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
