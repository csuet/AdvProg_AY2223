#include<bits/stdc++.h>
using namespace std;
int GenerateRandomNumber()
{
    srand(time(0));
    return rand()%100+1;
}
int PlayerGuess()
{
    int n;
    cout << "Guess a number(from 1...100): ";
    cin >> n;
    return n;
}
void PrintAnswer(int guess, int secretNum)
{
    int cnt = 0;
    int point = 100;
    secretNum = GenerateRandomNumber();
    do{
    cnt++;
    guess = PlayerGuess();
    if(guess < secretNum)
    {
        cout << "Your number is lower" << endl;
    }
    else if(guess > secretNum) cout << "Your number is higher" << endl;
    else cout << "Congratulations! You win." << endl;
    //cout << "-------------------------------" << endl;

    }
    while(guess != secretNum);
//    cout << " you guess " << cnt << " times!" << endl;
//    cout << " your point: " << point - cnt << endl;
}
void playGuessIt()
{
    int secretNum;
    int guess;
    PrintAnswer(guess,secretNum);
}
int main()
{
    string s;
    do{
        playGuessIt();
        cout <<"Wanna play again? ";
        cin >> s;
    }
    while(s == "yes" || s =="Yes" || s == "YES" || s == "y" || s == "Y");

    return 0;
}
