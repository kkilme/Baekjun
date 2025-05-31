// 2025-05-31 빙산
// 구현 / 그래프 이론 / 그래프 탐색 / BFS / DFS
#include <bits/stdc++.h>
using namespace std;

int n, m;
int mp[300][300]; 
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[300][300];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> mp[i][j];
        }
    }
    bool divided = false;
    int answer = 0;
    while (true)
    {   
        memset(visited, 0, sizeof(visited));
        bool flag = false;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mp[i][j] != 0 && !visited[i][j]){
                    if(flag) {divided = true; break;}
                    flag = true;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();
                        for(auto d: dir){
                            int nx = x + d[0];
                            int ny = y + d[1];
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if(mp[ny][nx] != 0 && !visited[ny][nx]){
                                visited[ny][nx] = true;
                                q.push({ny, nx});
                            }
                        }
                    }
                }
            }
        }
        if(divided) break;
        flag = false;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mp[i][j] != 0 && !visited[i][j]){
                    visited[i][j] = true;
                    flag = true;
                    for(auto d: dir){
                        if(mp[i][j] == 0) break;
                        int nx = j + d[0];
                        int ny = i + d[1];
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(visited[ny][nx]) continue;
                        if(mp[ny][nx] == 0) mp[i][j]--;
                    }
                }
            }
        }
        if(!flag) break;
        answer++;
    }
    
    if(!divided) cout << 0;
    else cout << answer;
}