// 2025-06-17 알고스팟
// 그래프 이론 / 그래프 탐색 / 최단 경로 / 다익스트라 / 격자 그래프 / 0-1 너비 우선 탐색?
#include <bits/stdc++.h>
using namespace std;

int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> m >> n;
    if(m == n && n == 1){
        cout << 0;
        return 0;
    }
    vector<string> maze(n);
    for(int i = 0; i<n; i++){
        cin >> maze[i];
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<>> q;
    vector<vector<int>> dist(n, vector<int>(m, 2e9));
    q.push({0, {0, 0}});
    dist[0][0] = 0;
    bool flag = true;
    while(!q.empty() && flag){
        int cur = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        for(auto d: dirs){
            int nw = cur;
            int nx = x + d[0];
            int ny = y + d[1];
            if(nx >= m || nx < 0 || ny >= n || ny < 0) continue;
            if(nx == m-1 && ny == n-1){
                cout << cur;
                flag = false;
                break;
            }
            if(maze[ny][nx] == '1') nw++;
            if(dist[ny][nx] > nw){
                dist[ny][nx] = nw;
                q.push({nw, {nx, ny}});
            }
        }
    }
}