// 2025-06-11 치즈
// 구현 / 그래프 이론 / 그래프 탐색 / 시뮬레이션 / BFS / 격자 그래프
#include <bits/stdc++.h>
using namespace std;

int board[100][100];
int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int cheesecnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int k;
            cin >> k;
            board[i][j] = k;
            if(k == 1) cheesecnt++;
        }
    }

    int time = 0;
    int last = 0;
    while(cheesecnt - last > 0){
        cheesecnt -= last;
        last = 0;
        bool visited[100][100] = {false,};
        visited[0][0] = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(auto d: dirs){
                int ny = y + d[0];
                int nx = x + d[1];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = true;
                if(board[ny][nx] == 1){
                    board[ny][nx] = 0;
                    last++;
                } else {
                    q.push({ny, nx});
                }
            }
        }
        time++;
    }

    cout << time << '\n' << last;

}