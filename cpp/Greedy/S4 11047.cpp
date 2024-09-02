// 2024-09-02 동전 0
// Greedy

#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, cnt=0;

    cin >> n >> k;

    int* coins = new int[n];

    for(int i = 0; i<n; i++){
        cin >> coins[i];
    }

    while(k != 0){
        cnt++;
        while(k < coins[n-1]) n--;
        k -= coins[n-1];
    }
    cout << cnt;
    
    delete[] coins;
}