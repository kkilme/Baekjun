// 2025-05-14 1학년
// DP
#include <bits/stdc++.h>
using namespace std;

long long dp[101][21];
int arr[101];

int main(){
    int n, last;
    cin >> n;

    for(int i = 0; i<n-1; i++){
        cin >> arr[i];
    }
    cin >> last;
    dp[0][arr[0]] = 1;

    for(int i = 1; i<n-1; i++){
        for(int j = 0; j<=20; j++){
            int k = j + arr[i];
            if(k <= 20){
                dp[i][k] += dp[i-1][j];
            }
            k = j - arr[i];
            if(k >= 0){
                dp[i][k] += dp[i-1][j];
            }
        }
    }
    cout << dp[n-2][last];
}