// 2025-07-07 치즈
// 구현 / 그래프 이론 / 그래프 탐색 / 시뮬레이션 / BFS / DFS / 격자 그래프
#include <bits/stdc++.h>
using namespace std;

int arr[100][100];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int t = 0;
    int visited[100][100];
    while(true){
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        queue<pair<int, int>> removed;
        q.push({0, 0});
        visited[0][0] = 1;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto d: dir){
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(arr[nr][nc] == 1){
                   if(++visited[nr][nc] == 2) removed.push({nr, nc});
                } else if(!visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        if(removed.empty()) break;
        while(!removed.empty()){
            int r = removed.front().first;
            int c = removed.front().second;
            removed.pop();
            arr[r][c] = 0;
        }
        t++;
    }

    cout << t;
}