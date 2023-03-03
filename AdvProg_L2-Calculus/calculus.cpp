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
   /* double sum = 1, sum_old;
    double dau = 1, tu = 1, mau = 1;
    int i = 0;
    while ( abs(sum - sum_old ) > 0.0001 ) {
            sum_old = sum;
            dau *= -1;
            tu *= x * x;
            i += 2;
            mau*= (i-1) * i;
            sum += dau * tu / mau;
    }
    return sum;*/
    return cos(x);
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double sqr(double x) {
    return x*x;
}
double mySin(double x)
{
 /*   double sum = x, sum_old;
    double dau = 1, tu = x, mau = 1;
    int i = 1;
    while ( abs(sum - sum_old ) > 0.0001 ) {
            sum_old = sum;
            dau *= -1;
            tu *= x * x;
            i += 2;
            mau*= (i-1) * i;
            sum += dau * tu / mau;
    }
    return sum;*/
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
/*double valu = 10, valu_old = 0;
    while (abs(valu - valu_old)> 0.00001) {
        valu_old = valu;
        valu = valu_old - (sqr(valu_old) - x) / (2 * valu_old);
    }
    return valu;*/

    return sqrt(x);
}
