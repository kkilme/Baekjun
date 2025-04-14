// 2025-04-15 헌내기는 친구가 필요해
// 그래프 이론 / 그래프 탐색 / BFS / DFS
#include <iostream>
#include <queue>
#include <string>
using namespace std;

string campus[600];
bool visited[600][600];
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    pair<int, int> start;

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> campus[i];
        for(int j = 0; j<m; j++){
            if(campus[i][j] == 'I') start = {i, j};
        }
    }

    int answer = 0;

    visited[start.first][start.second] = true;
    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(auto d: dir){
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && campus[nr][nc] != 'X' && !visited[nr][nc]){
                visited[nr][nc] = true;
                if(campus[nr][nc] == 'P') answer++;
                q.push({nr, nc});
            }
        }
    }
    if(!answer) cout << "TT";
    else cout << answer;
}