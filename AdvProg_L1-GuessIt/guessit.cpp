#include <iostream>
#include <cstdlib>

using namespace std;

int generateRandomNumber();
int getPlayerGuess();
void printAnswer(int number, int randomNumber);

int main()
{
    int randomNumber = generateRandomNumber();
    int number;

    do {
        number = getPlayerGuess();
        printAnswer(number, randomNumber);
    } while (number != randomNumber);

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
