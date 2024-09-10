// ATM
// 정렬

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0, prev=0;

    cin >> n;

    int ns[n];

    for(int i = 0; i<n; i++){
        cin >> ns[i];
    }

    sort(ns, ns+n);

    for(int i = 0; i<n; i++){
        prev += ns[i];
        sum += prev;
    }
    cout << sum;
}