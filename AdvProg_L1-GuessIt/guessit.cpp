#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

int generateRandomNumber() {
    int x = rand() % 100+1 ;  
    cout<<x ;  
    return x;
}

int getPlayerGuess() {
    int x ; cin>> x ; 
    return x;
}

string getAnswer(int number, int randomNumber) {
    string answer;
    if (number>randomNumber) answer="Your number is higher." ;
    if (number==randomNumber) answer="Congratulation! You win." ;
    if (number<randomNumber) answer="Your number is lower." ;
    return answer;
}

bool checkSuccess(string answer) {
    if (answer!="Congratulation! You win.") return false ; 
    return true;
}

bool checkContinuePlaying(char isContinued) {
    bool result = false;
    if (isContinued=='Y' || isContinued=='y') {return true ; } 
    return result;
}

char getPlayerOpinion() {
    char isContinued;
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
