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

double POW(double a, int n) {
	double answer = 1;
	for (int i = 1; i <= n; i++) {
		answer *= a;
	}
	return answer;
}

long gt(int n) {
	if (n == 0)
		return 1;
	return n * gt(n - 1);
}

double myCos(double x)
{
	int i = 0;
	const double EPSILON = 0.001;
	const double PI_TEST = 3.14159265359;
	double s = 0, s1 = 0, s2 = 0;
	x = x * PI_TEST / 180;
	do {
		s1 = s2;
		s = s + (POW(-1, i) * POW(x, 2 * i)) / gt(2 * i);
		s2 = s;
		i++;
	} while (fabs(s2 - s1) > EPSILON);
	return s2;
}

/***
	Args:
		x (double): a number
	Returns:
		double: sine of x
***/
double mySin(double x)
{
	int i = 0;
	const double EPSILON = 0.001;
	const double PI_TEST = 3.14159265359;
	double s = 0, s1 = 0, s2 = 0;
	x = x * PI_TEST / 180;
	do {
		s1 = s2;
		s = s + (POW(-1, i) * POW(x, 2 * i + 1)) / gt(2 * i + 1);
		s2 = s;
		i++;
	} while (fabs(s2 - s1) > EPSILON);
	return s2;
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
	const double EPSILON = 0.001;
	double result = 1.0f;
	while (fabs(result * result - x) / x >= EPSILON)
		result = (x / result - result) / 2 + result;
	return result;
}
