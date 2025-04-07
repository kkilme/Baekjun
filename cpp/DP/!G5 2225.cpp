// 2025-04-08 합분해
// 수학 / DP
// 중복 조합과 동일 nHk = n+k-1Ck-1
#include <iostream>

using namespace std;

int dp[201][201];
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i<=n; i++){
        dp[i][1] = 1;
    }
    for(int i = 0; i<=k; i++){
        dp[0][i] = 1;
    }
    for(int i = 2; i<=k; i++){
        for(int j = 1; j<=n; j++){
            dp[j][i] = (dp[j][i-1] + dp[j-1][i]) % 1000000000;
        }
    }

    cout << dp[n][k];
}