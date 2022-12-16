#include <iostream>
using namespace std;

int main(){

    double n, b, m;
    while(cin >> n >> b >> m){
        int year = 0;
        while(n <= m){
            year++;
            n+= n * (b/100);
        }
        cout << year << endl;
    }
}