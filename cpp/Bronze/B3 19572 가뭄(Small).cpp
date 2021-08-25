#include <iostream>

using namespace std;

int main(){

    int d1, d2, d3;
    float a,b,c;
    
    cin >> d1 >> d2 >> d3;

    a = (d1+d2-d3)/2.0;
    b = d1 - a;
    c = d2 - a;

    if (a>0 && b>0 && c>0)
    {
        cout << "1" << "\n";
        printf("%.1f %.1f %.1f", a,b,c);
    }
    else {cout << "-1";}
    
}