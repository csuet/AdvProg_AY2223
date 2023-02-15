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
    /*double c = 0, c_old=2;
    double temp = 1;
    int n = 1;
    while (c-c_old>=0.00001||c_old-c>=0.00001)
    {
        c_old = c;
        c = c+temp;
        temp = -x*x*temp/(n*(n+1));
        n=n+2;
    }
    return c;*/
    return cos(x);
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    /*double s = 0, s_old=2;
    double temp = x;
    int n = 2;
    while (s-s_old>=0.00001||s_old-s>=0.00001)
    {
        s_old = s;
        s = s+temp;
        temp = -x*x*temp/(n*(n+1));
        n=n+2;
    }
    return s;*/
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
    /*if (x>0)
	{
        double y=1.0;
        while (y-x/y>0.000001||x/y-y>0.000001)  y=(y+x/y)/2;
        return y;
	}
    return 0;*/
    return sqrt(x);
}
