// 2025-07-04 행렬 곱셈 순서
// DP
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[500][500]; // dp[i][j]: i~j번째 행렬 곱셈 연산 최솟값
int d[501]; // 행렬 크기 저장

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int a, b;
    cin >> a >> b;
    d[0] = a; d[1] = b;
    for(int i = 1; i<n; i++){
        cin >> a >> b;
        d[i+1] = b;
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j<n-i; j++){
            int last = j+i;
            int mn = INT32_MAX;
            for(int k = j; k<last; k++){
                mn = min(mn, dp[j][k] + dp[k+1][last] + d[j] * d[k+1] * d[last+1]); // a*b, b*c 행렬 곱셈 연산 횟수: a*b*c 
            }
            dp[j][last] = mn;
        }
    }

    cout << dp[0][n-1];
}