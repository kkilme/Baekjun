// 2024-09-10 소인수분해
// math

#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k = 2;

    cin >> n;

    while(k<=n){
        if(n % k == 0){
            cout << k << '\n';
            n /= k;
        } else k++;
    }
}