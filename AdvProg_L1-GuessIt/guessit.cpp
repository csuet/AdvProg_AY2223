#include <bits/stdc++.h>

#define ll long long

using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/***
    Args:

    Returns:
        number (int) : random number in range 1-100
***/
ll rd(ll l, ll r)
{
    ll h = (abs((ll)(rnd()))) % (r - l + 1);
    return h + l;
}
int generateRandomNumber()
{
    // TODO: Return the random number in range 1 to 100
    return rd(1, 100);
}

/***
    Args:

    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess()
{
    cout << "Guest some number" << endl;
    // TODO: Ask the player guest and return the player's number
    int n;
    cin >> n;
    return n;
}

/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber)
{
    /***
        TODO: check number with randomNumber and return the result.
              If number is higher than randomNumber, the answer is "Your number is higher."
              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
    if (number > randomNumber)
        return "Your number is higher.";
    else if (number < randomNumber)
        return "Your number is lower.";
    else
        return "Congratulation! You win.";
}

/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer)
{
    // TODO: return the result after checking that player guessed right or wrong

    if (answer == "Congratulation! You win.")
        return true;
    else
        return false;
}

/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued)
{
    // TODO: return result after checking player continue playing or not
    if (isContinued == 'Y' || isContinued == 'y') return true; 
    else return false; 
}

/***
    Args:

    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion()
{
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    cin >> isContinued;
    return isContinued;
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
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
