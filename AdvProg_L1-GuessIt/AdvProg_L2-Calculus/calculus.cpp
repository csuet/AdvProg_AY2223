#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std ;
// using std::string;
// using std::cout;
// using std::endl;
// using std::stod;


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
    return sqrt(x);
}
double hamso(string op , double number){
    if (op == "sin"){
        return mySin(number) ;
    }
    else {
        if ( op == "cos"){
            return myCos(number) ;
        }
        else {
            if (op = "sqrt"){
                return mySqrt(number) ;
            }
            else {
                cout << "Invalid operator." << endl ;
                exit(1) ;
            }
        }
    }
}
// double cal(double num1 , double num2 , char op){
//     switch (op) {
//         case '+' : {
//             return num1 + num2 ;
//         }
//         case '-' : {
//             return num1 - num 2 ; 
//         }
//         case '*' : {
//             return num1 * num 2 ; 
//         }
//         case '/' : {
//             if ( num2 == 0) {
//                 cout << "Invalid divisor" <<endl ;
//                 exit(1) ;
//             }
//             else {
//                 return num1 / num 2 ;
//             }
//         }
//         // case '%' : {
//         //     if ( num2 == 0) {
//         //         cout << "Invalid divisor" <<endl ;
//         //         exit(1) ;
//         //     }
//         //     else {
//         //         return num1 % num 2 ;
//         //     }
//         // }
//         default : {
//             cout << "Invalib operator" << endl ;
//             exit(1) ;
//         }
//     }
// }
int main(int argc ,char* argv[]){
    //if ( argc == 3){
        string op = argv[1] ;
        double number = atoi(argv[2]) ;
        cout << hamso(op, number) ;
        return 0 ;
    //}
    // else {
    //     double num1 , num2 ;
    //     char op ; 
    //     num1 = atoi(argv[1]) ;
    //     op = argv[2][0] ;
    //     num2 = atoi(argv[3]) ;
    //     cout << cal(num1 , num2 , op) << endl ;
    // }
}