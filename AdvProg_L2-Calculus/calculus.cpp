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

double trituyetdoi(double n) {
	if (n < 0) 
		return -n;
	else 
		return n;
}
double giaithua(double x) {
	if (x == 0) {
		return 1;
	}
	else {
		return x * giaithua(x - 1);
	}
}

double mu(double x, int n) {
	double result = 1;
	for (int i = 1; i <= n; i++) {
		result *= x;
	}
	return result;
}

double myCos(double x) {
	const double EPSILON = 0.001; // maximum difference between the expected result and returned result
	const double PI_TEST = 3.14159265359;
	double result = 0;
	double term = 1;
	double n = x * PI_TEST / 180;
	int i = 0;
	while (trituyetdoi(term) >= EPSILON) {
		term = (mu(-1, i) * mu(n, 2 * i)) / giaithua(2 * i);
		result += term;
		i++;
	}
	return result;
}
double mySin(double x) {
	const double EPSILON = 0.001; // maximum difference between the expected result and returned result
	const double PI_TEST = 3.14159265359;
	double result = 0;
	double term = 1;
	double n = x * PI_TEST / 180;
	int i = 0;
	while (trituyetdoi(term) >= EPSILON) {
		term = (mu(-1, i) * mu(n, 2 * i + 1)) / giaithua(2 * i + 1);
		result += term;
		i++;
	}
	return result;
}
/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
	const double EPSILON = 0.001; // maximum difference between the expected result and returned result
	if (x < 0) {
		return NULL;
	}
	if (x == 0) {
		return 0;
	}
	double guess = x / 2;
	while (trituyetdoi(guess * guess - x) > EPSILON) {
		guess = (guess + x / guess) / 2;
	}
	return guess;
}
