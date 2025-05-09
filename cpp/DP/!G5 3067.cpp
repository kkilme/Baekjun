// 2025-05-09 Coins
// DP / 배낭 문제
// 9084와 동일
#include <bits/stdc++.h>
using namespace std;

int coins[20];
int dp[10001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> coins[i];
        }
        int m;
        cin >> m;

        fill(dp, dp + 10001, 0);
        dp[0] = 1;
        for(int i = 0; i<n; i++){
            for(int j = coins[i]; j<=m; j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        cout << dp[m] << '\n';
    }
}