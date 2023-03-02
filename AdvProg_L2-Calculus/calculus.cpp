#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

const double EPSILON = 0.001;

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
    double cos = 1;
    double precos = 0;
    double temp = 1;
    double i = 1;
    while (std::abs(cos - precos) > EPSILON){
        temp = temp*x*x*(-1)/i/(i+1) ;
        precos = cos;
        cos += temp;
        i += 2;
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
    double sin = x;
    double presin = 0;
    double temp = x;
    double i = 2;
    while (std::abs(sin - presin) > EPSILON){
        temp = temp*x*x*(-1)/i/(i+1) ;
        presin = sin;
        sin += temp;
        i += 2;
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
    if (x == 0) return 0;
    double preres;
    double res = x/2;
    do {
        preres = res;
        res = (preres + x / preres) / 2;
    } while (std::abs(res - preres) > EPSILON);
    return res;
}