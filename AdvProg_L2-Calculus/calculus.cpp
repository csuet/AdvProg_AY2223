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
double factorial(int n);
double factorial(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double cos=1;
    double precos;
    int n = 2;
    while (abs(cos - precos) > 0.000001)
    {
        precos = cos;
        cos = precos + pow(-1, n / 2) * pow(x, n) / factorial(n);
        n = n + 2;
    }
    return cos;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sin = 0;
    double presin=1;
    int n = 1;
    while (abs(sin- presin) > 0.000001)
    {
        presin = sin;
        sin = presin + pow(-1, (n-1) / 2) * pow(x, n) / factorial(n);
        n = n + 2;
    }
    return sin;
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
    int sqrt = 10 - (10 * 10 - x) / 2 * 10;
    int presqrt;
    while (abs(sqrt - presqrt) > 0.00001)
    {
        presqrt = sqrt;
        sqrt = 1 / 2 * (presqrt + x / presqrt);
    }
    
    return sqrt;
}