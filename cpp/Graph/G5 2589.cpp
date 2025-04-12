// 2025-04-13 보물섬
// 그래프 이론 / 브루트포스 / 그래프 탐색 / BFS
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

string map[50];
bool visited[50][50];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int answer = 0;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cin >> map[i];
    }

    queue<pair<int,int>> q;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j] == 'W') continue;
            memset(visited, 0, sizeof(visited));
            visited[i][j] = true;
            q.push({i, j});
            int dist = 0;
            while(!q.empty()){
                int qsize = q.size();
                for(int k = 0; k<qsize; k++){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for(auto d: dir){
                        int nr = r + d[0];
                        int nc = c + d[1];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == 'L' && !visited[nr][nc]){
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
                dist++;
            }
            answer = max(dist-1, answer);

        }
    }
    cout << answer;
}