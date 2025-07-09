// 2025-07-10 다리 만들기
// 그래프 이론 / 그래프 탐색 / BFS / 격자 그래프
#include <bits/stdc++.h>
using namespace std;

int n;
int answer = 2e9;
bool mp[100][100];
int islands[100][100];
bool cango[100][100];
int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void makeIsland(int islandnum, int r, int c){
    queue<pair<int, int>> q;
    q.push({r, c});
    islands[r][c] = islandnum;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for(auto d: dirs){
            int nr = cr + d[0];
            int nc = cc + d[1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if(!mp[nr][nc]) cango[cr][cc] = true;
            if(mp[nr][nc] && islands[nr][nc] == 0){
                islands[nr][nc] = islandnum;
                q.push({nr, nc});
            }
        }
    }
}

void pathfind(int r, int c){
    int island = islands[r][c];
    queue<pair<int, int>> q;
    q.push({r, c});

    bool visited[100][100];
    memset(visited, 0, sizeof(visited));
    visited[r][c] = true;

    int dist = 0;
    bool done = false;
    while(!q.empty() && dist < answer){
        int sz = q.size();
        for(int i = 0; i<sz && !done; i++){
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for(auto d: dirs){
                int nr = cr + d[0];
                int nc = cc + d[1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) continue;
                if(islands[nr][nc] != 0 && islands[nr][nc] != island){
                    answer = dist;
                    done = true;
                    break;
                }
                if(!mp[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }            
        }
        dist++;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> mp[i][j];
        }
    }

    int islandnum = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(mp[i][j] && islands[i][j] == 0) makeIsland(islandnum++, i, j);
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(cango[i][j]) pathfind(i, j);
        }
    }

    cout << answer;
}