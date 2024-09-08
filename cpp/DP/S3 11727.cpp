// 2024-09-08 2xn 타일링 2
// DP

#include <iostream>

using namespace std;

int main(){

    int dp[1000];
    dp[0] = 1; dp[1] = 3;
    for(int i = 2; i<1000; i++){
        dp[i] = (dp[i-1] + 2*dp[i-2])%10007;
    }
    int n;
    cin >> n;
    cout << dp[n-1];
}