#include <iostream>
#include "hello.h"
// #include "SDL.h"
using namespace std;

void convert(string& s) {
    for (int i = 0; i < (int)s.size(); i++ ) {
        if (i == 0 || s[i - 1] == ' ') {
            if ('a' <= s[i] && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
        }
        if ( i > 0 && s[i-1] != ' ' && s[i] >= 'A' && s[i] <= 'Z' ) s[i] += 32;
    }
}

int main(){
    cout << printGameOver();
    
}