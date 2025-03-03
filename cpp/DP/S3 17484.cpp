// 2025-03-03 진우의 달 여행 (Small)
#include <iostream>

using namespace std;

int map[1000][1000];
int dp[1000][1000][3];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int k;
            cin >> k;
            map[i][j] = k;
        }
    }

    for(int i = 0; i<m; i++){
        dp[0][i][0] = map[0][i];
        dp[0][i][1] = map[0][i];
        dp[0][i][2] = map[0][i];
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){
            if(j == 0){
                dp[i][j][0] = 2e9;
                dp[i][j][1] = dp[i-1][j][2] + map[i][j];
                dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + map[i][j];
            } else if(j == m-1){
                dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + map[i][j];
                dp[i][j][1] = dp[i-1][j][0] + map[i][j];
                dp[i][j][2] = 2e9;
            } else {
                dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + map[i][j];
                dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + map[i][j];
                dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + map[i][j];
            }
        }
    }

    int ans = 2e9;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<3; j++){
            ans = min(ans, dp[n-1][i][j]);
        }
    }
    
    cout << ans;
}