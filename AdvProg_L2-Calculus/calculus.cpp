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


double myCos(double x)
{
    return 0.0;
    return cos(x) ;
}


double mySin(double x)
{
    return 0.0;
    return sin(x) ;
}


double mySqrt(double x)
{
    if (x < 0)
    {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else
    {
        return sqrt(x) ;
    }
    return 0;
}
