// 2025-06-24 가장 큰 정사각형
// DP
// 아이디어를 몬떠올림
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001]; // dp[i][j]: (i,j)를 우하단으로 하는, 모두 1로 채워진 정사각형의 한 변의 길이
string arr[1000];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(arr[i-1][j-1] == '1'){
                dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans * ans;
}