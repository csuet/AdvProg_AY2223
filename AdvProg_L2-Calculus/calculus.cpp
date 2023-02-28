#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double so_hang = 1, ans = 1;
    for (int i = 2; i <= 30; i++) {
        so_hang *= - x * x / i / (i - 1);
        ans += so_hang;
    }
    return ans;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double so_hang = x, ans = x;
    for (int i = 2; i <= 30; i++) {
        so_hang *= - x * x / i / (i + 1);
        ans += so_hang;
    }
    return ans;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double prev = 10, now = 0;
    while (abs (now - prev) < 0.00001)
        now = prev - (prev * prev - x) / 2 / prev;
    
    return now;
}