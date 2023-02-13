#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

int generateRandomNumber()
{
    return rand()%100+1 ;
}

int getPlayerGuess()
{
    int number ;
    cout << "Please, enter the number you guess (from 1 to 100): " ;
    cin >> number ;
    return number ;
}

string getAnswer(int number, int randomNumber)
{
    string answer ;
    if(number < randomNumber)
    {
        answer = "The number is too small!" ;
    }
    else if(number > randomNumber)
    {
        answer = "The number is too large!" ;
    }
    else
    {
        answer = "You are the winner. Congratulation!" ;
    }
    return answer ;
}

bool checkSuccess(string answer)
{
    if (answer == "You are the winner. Congratulation!")
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
    bool result ;
    if (isContinued == 'Y' || isContinued == 'y')
    {
        result = true;
    }
    else
    {
        result = false ;
    }
    return result;
}

char getPlayerOpinion()
{
    char isContinued;
    cout << "Do you want to play again? [Y/N]: " ;
    cin >> isContinued ;
    return isContinued ;
}

void playGuessIt()
{
    int randomNumber = generateRandomNumber();
    int number;
    string answer;
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

