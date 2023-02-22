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
    double accurcy = 0.001;
    double cosx, cosval;
    double denominator;
    cosx = 1;
    double temp = 1;
    int i = 1;
    do
    {
        denominator = (2 * i) * (2 * i - 1);
        cosval = cosx;
        temp = -temp * x * x / denominator;
        cosx = cosx + temp;
        i++;
    } 
    while (fabs(cosx - cosval) >= accurcy);
    
    return cosx;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double mySin(double x)
{
    double accurcy = 0.001;
    double sinx, sinval;
    double denominator;
    sinx = x;
    double temp = x;
    int i = 1;
    do
    {
        denominator = (2 * i) * (2 * i + 1);
        sinval = sinx;
        temp = -temp * x * x / denominator;
        sinx = sinx + temp;
        i++;
    } 
    while (fabs(sinx - sinval) >= accurcy);

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
    double saiso = 0.001;
    double result = 0;
    double pre_result = 10;

    do
    {
        result = pre_result - ((pre_result * pre_result - x) / (2.0 * pre_result));
        if (fabs(result - pre_result) < saiso)
        {
            //End loop
            break;
        }
        else
        {
            //Continue Loop
            pre_result = result;
            continue;
        }
    } while (true);

    return result;
}