#include <bits/stdc++.h>
using namespace std;
int generateRandomNumber()
{return rand()%100+1;}//nghi so
//rand%(max-min+1)+min
int getPlayerGuess()
{
    int guess;
    cout << endl << "Enter your Guess: ";
    cin >> guess;
    return guess;
}

void printAnswer(int guess, int secretNumber)
{
    if(guess > secretNumber){cout << "Your  number is too big !" << endl;}
    else if(guess < secretNumber){cout << "Your number is too small!" << endl;}
    else {cout << "Congratulation! You win.";}
}
int main()
{   srand(time(0));
    int num1 = generateRandomNumber();
    int number;
    do {
        number =  getPlayerGuess();
        printAnswer(number,num1);
    }while( number != num1);
return 0;
}

