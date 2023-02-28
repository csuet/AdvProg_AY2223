#include <bits/stdc++.h>
using namespace std;

int main() {
    double ang = 60;
    int numpixels = 30;
    cout << numpixels * cos(ang / 180 * M_PI) << ' ' << numpixels * sin(ang / 180 * M_PI) << endl;
}