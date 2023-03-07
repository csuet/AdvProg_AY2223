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

const double eps = 1e-8;

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    double res = 0;
    int n = 0;
    long long fact = 1;
    do{
       fact = fact * (2 * n - 1) * (2 * n);
       if(fact < 1) fact = 1;
       res += pow(-1, n) / fact * pow(x, 2 * n);
       n ++;
    }while(n < 10);
    return res;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double res = 0;
    int n = 0;
    long long fact = 1;
    do{
       fact *= (2 * n) * (2 * n + 1);
       if(fact == 0) fact = 1;
       res += pow(-1, n) / fact * pow(x, 2 * n + 1);
       n ++;
    }while(n < 10);
    return res;
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
    if(x == 0) return 0;
    double res = x;
    for(int _ = 10; _; _ --){
       res = 0.5 * (res + x / res);
    }
    return res;
}
