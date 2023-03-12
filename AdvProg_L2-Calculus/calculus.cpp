#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

#define EPSILON 0.0001f

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
    int n=1;
    double s=0, t=1.0;
    while(fabs(t) >= 1e-6) {
        s+=t;
        t*=(-1)*x*x/(n*(n+1));
        n=n+2;
    }
    return s;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{

    return sin(x);
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
        double result = 1.0f;
    while (fabs(result * result - x) / x>= EPSILON)
        result = (x / result  - result) / 2 + result;
    return result;




    

}