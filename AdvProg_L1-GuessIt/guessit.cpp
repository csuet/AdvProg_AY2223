#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

int generateRandomNumber()
{
    return rand()%100 + 1 ;
}

int getPlayerGuess() 
{
    int number;
    cout << "Enter yours guess (1..100): ";
    cin >> number;
    return number;
}

string getAnswer(int number, int randomNumber)
{
    string answer ;
    if(number < randomNumber)
    {
       answer = "Your number is lower.";
    }
    else if(number > randomNumber)
    {
         answer = "Your number is higher.";
    }
    else
    {
        answer = "Congratulation! You win.";
    }
    return answer ;
}

bool checkSuccess(string answer)
{
    if (answer == "Congratulation! You win.") 
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkContinuePlaying(char isContinued) 
{
    bool result = false ;
    if (isContinued == 'Y' || isContinued == 'y') 
    {
        result = true ;
    }
    return result ;
}

char getPlayerOpinion()
{
    char isContinued;
    cin >> isContinued ;
    return isContinued ;
}

void playGuessIt()
{
    int randomNumber = generateRandomNumber() ;
    int number ;
    string answer ;
    do 
    {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run()
{
    srand(time(0));
    char isContinued;
    do
    {
        playGuessIt();
        isContinued = getPlayerOpinion() ;
    } while (checkContinuePlaying(isContinued)) ;
    return 0;
}

