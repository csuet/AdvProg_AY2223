#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber();
int getPlayerGuess();
void printAnswer(int number, int randomNumber);
void playGuessIt();

int main()
{
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        cout << endl << "Do you want to play again (y/n) ?  ";
        cin >> isContinued;
    } while (isContinued == 'y' || isContinued == 'Y');
    return 0;
}

int generateRandomNumber()
{
    return rand() % 100 + 1;
}

int getPlayerGuess()
{
    int number;
    cout << endl << "Enter your number between 1 and 100: ";
    cin >> number;
    return number;
}

void printAnswer(int number, int randomNumber)
{
    if (number > randomNumber) {
        cout <<"Your number is higher." << endl;
    } else if (number < randomNumber) {
        cout <<"Your number is lower." << endl;
    } else {
        cout << "Congratulation! You win." << endl;
    }
}

void playGuessIt()
{
    int randomNumber = generateRandomNumber();
    int number;

    do {
        number = getPlayerGuess();
        printAnswer(number, randomNumber);
    } while (number != randomNumber);
}