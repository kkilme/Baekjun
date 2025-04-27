// 2025-04-27 RGB 거리
// DP
#include <bits/stdc++.h>
using namespace std;

int colors[1001][3];
int dp[1001][3];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
    }

    dp[0][0] = colors[0][0];
    dp[0][1] = colors[0][1];
    dp[0][2] = colors[0][2];

    for(int i = 1; i<n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + colors[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + colors[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + colors[i][2];
    }

    int result = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << result;
}