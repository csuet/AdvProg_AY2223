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
    double cosx = 1, temp = 1;
    for (int i = 2; i < 40; i += 2)
    {
        temp *= -(x*x)/(i*(i-1));
        cosx += temp;
    }
    return cosx;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sinx = 1, temp = 1;
    for (int i = 3; i < 40; i += 2)
    {
        temp *= -(x*x)/(i*(i-1));
        cosx += temp;
    }
    return sinx;
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
    double sqrtx = 1;
    for (int i = 0; i < 20; i++)
    {
        sqrtx = (sqrtx + x/sqrtx) / 2;
    }
    return sqrtx;
}
