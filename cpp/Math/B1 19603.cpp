// 2024-09-10 Epidemiology
// math

#include <iostream>

using namespace std;

int main(){

    int p, n, r;

    cin >> p >> n >> r;

    int cur = n, day = 0;

    while(cur <= p){
        day++;
        n = n*r;
        cur += n;
    }

    cout << day;
}