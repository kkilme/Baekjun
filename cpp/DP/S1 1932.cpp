// 2025-04-28 정수 삼각형
// DP
#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
int dp[501][501];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=i; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j] + arr[i][j];
            } else if(j == i){
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
            }
        }
    }

    cout << *max_element(dp[n-1], dp[n-1] + n) << "\n";
}