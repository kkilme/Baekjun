// 2025-03-14 쉬운 최단거리
// 그래프 이론 / 그래프 탐색 / BFS
// 다익스트라로 품
#include <iostream>
#include <queue>
using namespace std;

int map[1000][1000];
int dist[1000][1000];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m;
    cin >> n >> m;
    priority_queue<pair<int,int>> pq;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            dist[i][j] = 2e9;
            int k;
            cin >> k;
            if(k == 2) {
                pq.push({i,j});
                dist[i][j] = 0;
            }
            map[i][j] = k;
        }
    }

    while (!pq.empty())
    {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();

        for(auto d: dir){
            int nx = x + d[0];
            int ny = y + d[1];
            if(nx >=0 && nx < n && ny >=0 && ny < m && map[nx][ny] != 0 && dist[nx][ny] > dist[x][y] + 1){
                dist[nx][ny] = dist[x][y] + 1;
                pq.push({nx, ny});
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j] == 0) cout << "0 ";
            else if(dist[i][j] == 2e9) cout << "-1 ";
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    
}