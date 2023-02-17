#include<bits/stdc++.h>
using namespace std;
const string word[] = {"VUONGQUOC", "NQVUONG", "IMTHEKING", "CHATGPT", "YEU", "HICHAOCAU"};
const string FIGURE[] = {"--------------  \n"
                        "|                 \n"
                        "|                 \n"
                        "|                 \n"
                        "|                 \n"
                        "|         \n"
                        " -------   \n",
                        "--------------  \n"
                        "|             |  \n"
                        "|                 \n"
                        "|                 \n"
                        "|                 \n"
                        "|         \n"
                        " -------   \n",
                         "--------------  \n"
                        "|             |  \n"
                        "|             0    \n"
                        "|                 \n"
                        "|                 \n"
                        "|         \n"
                        " -------   \n"
                        "--------------  \n"
                        "|             |  \n"
                        "|             0    \n"
                        "|             |   \n"
                        "|                 \n"
                        "|         \n"
                        " -------   \n",
                        "--------------  \n"
                        "|             |  \n"
                        "|             0    \n"
                        "|            /|    \n"
                        "|                 \n"
                        "|         \n"
                        " -------   \n",
                        "--------------  \n"
                        "|             |  \n"
                        "|             0    \n"
                        "|            /|\\   \n"
                        "|                \n"
                        "|         \n"
                        " -------   \n",
                        "--------------  \n"
                        "|             |  \n"
                        "|             0    \n"
                        "|            /|\\   \n"
                        "|            /     \n"
                        "|         \n"
                        " -------   \n",
                         "--------------  \n"
                        "|             |  \n"
                        "|             0    \n"
                        "|            /|\\   \n"
                        "|            / \\  \n"
                        "|         \n"
                        " -------   \n"};
string chooseWord(){ //chon tu de doan
    return word[rand() % 6];
}

char readAGuess(){ //nhap 1 ki tu
    char word; cin >> word ;
    return toupper(word);
}


string update(string guessWord, string secretWord, char guess){
    for(int i=0; i < secretWord.size(); i++){
        if(secretWord[i] == guess) guessWord[i] = guess;
    }
    return guessWord;
}


void renderGame(string guesseWord, int badGuessCount){
    cout << FIGURE[badGuessCount] << endl;
    cout << guesseWord << endl;
    cout << "Number of wrong guesses : " << badGuessCount << endl;
}


bool contains(string secretWord, char word){ // check ki tu
    for(int i=0; i<secretWord.size(); i++){
        if(secretWord[i] == word) return true;
    }
    return false;

}


int main(){
string secretWord = chooseWord();
string guessedWord = string(secretWord.length(), '-');
int badGuessCount = 0;
do {
renderGame(guessedWord, badGuessCount);
char guess = readAGuess();
if (contains(secretWord, guess))
guessedWord = update(guessedWord, secretWord, guess);
else badGuessCount++;
} while (badGuessCount < 7 && secretWord != guessedWord);
 renderGame(guessedWord, badGuessCount);
if (badGuessCount < 7) cout << "Congratulations! You win!";
else cout << "You lost. The correct word is " << secretWord;
    return 0;
}
