#include<bits/stdc++.h>
using namespace std; 
const string word[] = {"NGUYENQUANGCUONG", "NXBER", "QUOCANHPHAM", "CHATGPT", "HIEUDOAN", "TAPLAMDEV", "TRANDINHTUAN"};
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
string chooseWord(){ // so cap 
    return word[rand() % 7 + 1];
}

char readAGuess(){ // nhap tu 
    char word; cin >> word ;
    return toupper(word);
}


string update(string guessWord, string secretWord, char guess){ // ham update 
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


bool contains(string secretWord, char word){ // check ky tu 
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
