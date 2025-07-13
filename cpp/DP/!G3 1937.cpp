// 2025-07-13 욕심쟁이 판다
// DP / 그래프 이론 / 그래프 탐색 / DFS? / 격자 그래프
#include <bits/stdc++.h>
using namespace std;

int answer = 1;
int forest[500][500];
int dp[500][500];
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v;
    int a;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> a;
            forest[i][j] = a;
            dp[i][j] = 1;
            v.push_back({a, {i, j}});
        }
    }

    sort(v.begin(), v.end()); // 대나무 수 오름차순으로 정렬하면

    for(int k = 0; k<v.size(); k++){
        int r = v[k].second.first;
        int c = v[k].second.second;
        
        for(auto d: dirs){
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if(forest[nr][nc] > forest[r][c]){
                dp[nr][nc] = max(dp[nr][nc], dp[r][c] + 1); // dp가 항상 높은쪽으로만 전파되어, 최종 dp[r][c]는 그 칸을 시작으로 해서 갈 수 있는 지점 개수가 됨 - 또는 재귀 dfs로 풀수도
                answer = max(dp[nr][nc], answer);
            }
        }
    }
    cout << answer;
}