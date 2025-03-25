// 2025-03-26 적록색약
// 그래프 이론 / 그래프 탐색 / BFS / DFS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool visited[100][100];
vector<string> pic(100);

void bfs(int i, int j, bool isBlind){
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]){
                if(isBlind){
                    if(pic[x][y] == 'B' && pic[nx][ny] != 'B') continue;
                    if(pic[x][y] != 'B' && pic[nx][ny] == 'B') continue;
                } else {
                    if(pic[x][y] != pic[nx][ny]) continue;
                }
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> pic[i];
    int cnt = 0, cntBlind = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                bfs(i, j, false);
                cnt++;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                bfs(i, j, true);
                cntBlind++;
            }
        }
    }
    cout << cnt << ' ' << cntBlind << endl;
}