#include<bits/stdc++.h>
using namespace std;

void updateEnteredChars(const char ch, string& chars){
    // TODO: append the character ch is in end of the text chars
    chars =chars +  " " + ch;
    cout << chars;
}
int main(){
    string chars; cin >> chars;
    char ch; cin >> ch;
    updateEnteredChars(ch,chars);
    return 0;
}