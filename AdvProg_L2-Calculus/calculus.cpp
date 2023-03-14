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
    double result = 1, tmp = 1;
    const int MAX_DEG = 39;
    for (int i = 2; i <= MAX_DEG; i += 2)
    {
        tmp *= -x * x / (i * (i - 1));
        result += tmp;
    }
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double result = x, tmp = x;
    const int MAX_DEG = 39;
    for (int i = 3; i <= MAX_DEG; i += 2)
    {
        tmp *= -x * x/ (i * (i - 1));
        result += tmp;
    }
    return result;
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
    double result = 1;
    const int STEPS = 20;
    for (int i = 0; i < STEPS; ++i)
        result = (result + x / result) / 2;
    return result;
}