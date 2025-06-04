// 2025-06-05 타일 채우기
// DP
// 점화식 추론해내기가 어려움
// 3 * dp[i-2]를 떠올리긴 쉽지만 이외 경우의 수를 찾아서 식으로 표현하는 게 어려움
#include <bits/stdc++.h>
using namespace std;

long long dp[31];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    dp[2] = 3; dp[4] = 11;
    for(int i = 6; i<=30; i++){
        dp[i] = 4 * dp[i-2] - dp[i-4];
    }

    cout << dp[n];

}
/*
dp[0] = 1
dp[i] = dp[i - 2] * 3 + dp[i - 4] * 2 + dp[i - 6] * 2 ... dp[0] * 2
dp[i] = dp[i - 2] * 3 + dp[i - 4] * 2 + dp[i - 6] * 2 ... dp[0] * 2 + dp[i - 2]  - dp[i - 2]

dp[i - 2] = dp[i - 4] * 3 + dp[i - 6] * 2 + dp[i - 8] * 2 ... dp[0] * 2이므로 
dp[i] = dp[i - 2] * 4 + dp[i - 4] * 2 + dp[i - 6] * 2 ... dp[0] * 2 - (dp[i - 4] * 3 + dp[i - 6] * 2 + dp[i - 8] * 2 ... dp[0] * 2)
= dp[i - 2] * 4 + dp[i - 4] * -1 + 0 + 0 + ... + 0
dp[i] = 4 * dp[i-2] - dp[i-4]
*/