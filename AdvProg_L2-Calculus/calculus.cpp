#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::stod;
using std::string;

double mySin(double x);
double myCos(double x);
double mySqrt(double x);

double myCos(double x)
{
    double result = 1, tmp = 1;
    int N = 39;
    for (int i = 2; i <= N; i += 2)
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
    int N = 39;
    for (int i = 3; i <= N; i += 2)
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
        double: square root of x
***/
double mySqrt(double x)
{
    double result = 1;
    int N = 20;
    for (int i = 0; i < N; ++i)
        result = (result + x / result) / 2;
    return result;
}