// 2025-05-05 퇴사
// DP
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[16];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int ans = 0;
    int t, p;
    for(int i = 1; i<=n; i++){
        cin >> t >> p;
        dp[i] = max(dp[i], dp[i-1]);
        ans = max(ans, dp[i]);
        if(i+t > n+1) continue;
        dp[i+t-1] = max(dp[i+t-1], dp[i-1] + p);
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
}