#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

int main(){

    long long a;
    double b;
    cin >> a;
    b = 2 * sqrt(a / M_PI) * M_PI;
    cout.precision(20);
    cout << b;
}