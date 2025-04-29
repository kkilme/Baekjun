// 2025-04-29 스티커
// DP
#include <bits/stdc++.h>
using namespace std;

int arr[100001][2];
int dp[100001][2];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int j = 0; j<2; j++){
            for(int i = 0; i<n; i++){
                cin >> arr[i][j];
            }
        }
        fill(dp[0], dp[0] + 100001*2, 0);
        dp[0][0] = arr[0][0]; dp[0][1] = arr[0][1];
        dp[1][0] = arr[1][0] + dp[0][1]; dp[1][1] = arr[1][1] + dp[0][0];
        for(int i = 2; i<n; i++){
            dp[i][0] = max({dp[i-1][1], dp[i-2][0], dp[i-2][1]}) + arr[i][0];
            dp[i][1] = max({dp[i-1][0], dp[i-2][0], dp[i-2][1]}) + arr[i][1];
        }
        cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
    }
}