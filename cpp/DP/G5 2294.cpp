// 2025-04-06 동전 2
// DP
#include <iostream>

using namespace std;
int value[10001];
int coins[100];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    fill(value, value + 10001, 10001);
    for(int i = 0; i < n; i++){
        if(coins[i] < 10001) value[coins[i]] = 1;
    }
    for(int i = 1; i<=k; i++){
        for(int j = 0; j<n; j++){
            if(i - coins[j] >= 0){
                value[i] = min(value[i], value[i - coins[j]] + 1);
            }
        }
    }
    cout << (value[k] == 10001 ? -1 : value[k]) << endl;
}