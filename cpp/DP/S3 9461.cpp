// 2024-09-05 파도반 수열
// DP

#include <iostream>

using namespace std;

int main(){

    int t, n;
    long long dp[101]; dp[1] = dp[2] = dp[3] = 1; dp[4] = dp[5] = 2;

    for(int i = 6; i<101; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }

    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
    
}