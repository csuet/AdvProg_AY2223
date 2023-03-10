#include <iostream>
#include <string>
#include <cmath>
#include "calculus.h"

using std::string;
using std::cout;
using std::endl;
using std::stod;

const string PREFIX = "lib_";

double callFunction(string func, double x);

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "Invalid arguments" << endl;
        return 1;
    }

    string func = argv[1];
    double x = stod(argv[2]);
    cout << "Computed by this program:  " << callFunction(func, x) << endl;
    cout << "Computed by C/C++ library: " << callFunction(PREFIX + func, x) << endl;
    
    return 0;
}

double callFunction(string func, double x)
{
    if (func == "cos") {
        return myCos(x);
    } else if (func == "sin") {
        return mySin(x);
    } else if (func == "sqrt") {
        return mySqrt(x);
    } else if (func == PREFIX + "cos") {
        return cos(x);
    } else if (func == PREFIX + "sin") {
        return sin(x);
    } else if (func == PREFIX + "sqrt") {
        return sqrt(x);
    } else {
        cout << "Invalid function" << endl;
        exit(1);
    }
}
