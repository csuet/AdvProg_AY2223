#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<conio.h>
#include<cctype>
#include<Windows.h>

#define MAX_BAD_GUESSES 7
using namespace std;

//Define func
string choose_word();
void rendergame(int& badguess, string& out1, string& out2);
char TakeAGuess();
bool Result(string& word, char& guess, string& out1, string& out2);
bool Winner(string& out1);
void SetWindowSize(short width, short height);

int main() {

    string play;
    bool playagain = true;
    //Replay
    while (playagain) {
        string choice = choose_word();
        int BAD_GUESS = 0;
        string out1, out2;
        char a; bool b;

        for (int i = 0; i < choice.length(); i++) out1 += '-';
        rendergame(BAD_GUESS, out1, out2);
        do {
            a = TakeAGuess();
            b = Result(choice, a, out1, out2);
            BAD_GUESS += b;
            rendergame(BAD_GUESS, out1, out2);
            if (Winner(out1)) break;
        } while (BAD_GUESS <= MAX_BAD_GUESSES);

        //Test win or lose
        int check = BAD_GUESS;
        if (check <= 7) {
            system("cls");
            cout << "CONGRATULATION" << "\n\n\n\n\n\n\n\n";
            Sleep(1000); system("cls");
            cout << "PLAY AGAIN? (Y/N)"; cin >> play;
            if (play == "N" or play == "n") {
                system("cls");
                playagain = false;
            }
        }
        else {
            system("cls");
            cout << "**********TO BAD,YOU LOSE*********" << endl;
            Sleep(1000); system("cls");
            cout << "PLAY AGAIN? (Y/N)"; cin >> play;
            if (play == "N" or play == "n") {
                system("cls");
                playagain = false;
            }
        }
    }
    return 0;
}

const string WORD_LIST[] = {
    "angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame",
        "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house",
        "island", "jewel",
        "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun",
        "table", "tail", "thread", "throat", "thumb", "ticket", "toe", "tongue", "tooth",
        "town", "train", "tray", "tree", "trousers",
        "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"
};

const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);

const string FIGURE[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
};

string choose_word() {
    srand(time(0));
    int Index_Num = rand() % WORD_COUNT;
    return WORD_LIST[Index_Num];
}

void rendergame(int& badguess, string& out1, string& out2) {
    system("cls");
    cout << FIGURE[badguess];

    printf("Word to guess: %s\n", out1.c_str());
    printf("wrong guess: %s\n", out2.c_str());
}

char TakeAGuess() {
    char a; cin >> a;
    return tolower(a);
}

bool Result(string& word, char& guess, string& out1, string& out2) {
    int cnt = 0;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == guess) {
            cnt++;
            out1[i] = word[i];
            word[i] = ' ';
        }
    }
    if (cnt == 0) {
        out2 += guess;
        return true;
    }
    return false;
}

bool Winner(string& out1) {
    for (int i = 0; i < out1.length(); i++) {
        if (out1[i] == '-') return false;
    }
    return true;
}

void SetWindowSize(short width, short height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

