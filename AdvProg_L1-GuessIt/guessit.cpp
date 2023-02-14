#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber()
{
	int n = rand() % 100 + 1;
    return n;
}

int getPlayerGuess()
{
    cout << endl << "Enter your number between 1 and 100: ";
    int number;
    cin >> number;
    return number;
}

void printAnswer(int number, int randomNumber)
{
    if (number > randomNumber) {
        cout <<"Your number is higher.\n";
    } else if (number < randomNumber) {
        cout <<"Your number is lower.\n";
    } else {
        cout << "Congratulation! You win.\n";
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

