// 2025-04-20 미로 탐색
// 그래프 이론 / 그래프 탐색 / BFS?
// 다익스트라로 품
#include <bits/stdc++.h>
using namespace std;

int n, m;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string maze[101];
int dist[101][101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(&dist[0][0], &dist[100][101], 2e9);

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cin >> maze[i];
    }

    priority_queue<pair<int, int>> q;
    
    q.push({0, 0});
    dist[0][0] = 1;
    while(!q.empty())
    {
        int r = q.top().first;
        int c = q.top().second;

        q.pop();
        for(auto d: dir){
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr >= 0 && nr < n && nc >=0 && nc < m && maze[nr][nc] == '1' && dist[nr][nc] > dist[r][c] + 1){
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc}); 
            }
        }
    }
    cout << dist[n-1][m-1];
}