// 2025-06-29 내리막 길
// DP / 그래프 이론 / 그래프 탐색 / DFS / 격자 그래프
#include <bits/stdc++.h>
using namespace std;

int m, n;
int mp[500][500];
int dp[500][500]; // 메모이제이션
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int r, int c){
    if(dp[r][c] != -1){
        return dp[r][c];
    } else if(r == m-1 && c == n-1) return 1;
    int sum = 0;
    for(auto d: dir){
        int nr = r + d[0];
        int nc = c + d[1];
        if(nr < 0 || nr >= m || nc < 0 || nc >= n || mp[nr][nc] >= mp[r][c]) continue;
        sum += dfs(nr, nc);
    }
    dp[r][c] = sum;
    return sum;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> mp[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0);
}