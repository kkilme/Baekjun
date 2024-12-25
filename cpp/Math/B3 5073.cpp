// 2024-12-25 삼각형과 세 변
// Math

#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int a, b, c;
    while(1){
        cin >> a >> b >> c;
        if(a + b + c == 0) break;


        if(a == b && b == c){
            cout << "Equilateral\n";
            continue;
        }

        int m = max({a, b, c});

        if(m < a + b + c - m){
            if(a == b || b == c || a == c){
                cout << "Isosceles\n";
            } else cout << "Scalene\n";
        } else cout << "Invalid\n";
    }
}