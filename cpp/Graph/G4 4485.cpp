// 2025-01-21 녹색 옷 입은 애가 젤다지?
// 다익스트라 / 그래프 이론 / 그래프 탐색 / 최단 경로
#include <iostream>
#include <queue>
using namespace std;

int t, n, map[126][126], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 1;
    while(true){
        cin >> n;
        if(n == 0) break;
        int dist[126][126];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin >> map[i][j];
                dist[i][j] = 2e9;
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;

        dist[0][0] = map[0][0];
        pq.push({-map[0][0], {0, 0}});

        while(!pq.empty()){
            int cost = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(dist[x][y] < cost) continue;

            for(int i = 0; i<4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                if(dist[nx][ny] > cost + map[nx][ny]){
                    dist[nx][ny] = cost + map[nx][ny];
                    pq.push({-dist[nx][ny], {nx, ny}});
                }
            }
        }
        cout << "Problem " << count++ << ": " << dist[n-1][n-1] << "\n";
    }
}