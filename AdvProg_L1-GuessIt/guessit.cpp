#include "guessit.h"

using namespace std;

int generateRandomNumber() {
    return rand()%101;
}


int getPlayerGuess() {
    cout<<"Enter your Guess"<<endl;
    int guess;
    cin>>guess;


    return guess;
}

string getAnswer(int number, int randomNumber) {
    string answer;
    if( number > randomNumber ) answer="Your number is higher. ";
    if( number < randomNumber ) answer="Your number is lower.";
    else answer="Congratulation! You win.";
    return answer;
}

bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong
    if( answer=="Congratulation! You win." ) return true;
    return false;
}


bool checkContinuePlaying(char isContinued) {
    bool result = false;
    if ( isContinued=='y' || isContinued=='Y') return true;
    else if ( isContinued=='n' || isContinued=='N') return false;
    return result;
}


char getPlayerOpinion() {
    char isContinued;
    cout<<"Do you want to continues playing?";
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


