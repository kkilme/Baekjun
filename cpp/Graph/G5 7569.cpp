// 2025-03-27 토마토
// 그래프 이론 / 그래프 탐색 / BFS
#include <iostream>
#include <queue>
using namespace std;

struct tomato{
    int x, y, z;
};

int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
int box[100][100][100];
queue<tomato> q;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, h;
    cin >> m >> n >> h;
    int cnt = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                int p;
                cin >> p;
                if(p == 1) {
                    q.push({k, j, i});
                } else if(p == 0) {
                    cnt++;
                }
                box[i][j][k] = p;
            }
        }
    }

    int day = -1;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i<size; i++){
            tomato cur = q.front();
            q.pop();
            int x = cur.x;
            int y = cur.y;
            int z = cur.z;
            for(int j = 0; j<6; j++){
                int nx = x + dir[j][0];
                int ny = y + dir[j][1];
                int nz = z + dir[j][2];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
                if(box[nz][ny][nx] == 0){
                    box[nz][ny][nx] = 1;
                    q.push({nx, ny, nz});
                    cnt--;
                }
            }
        }
        day++;
    }
    if(cnt == 0) cout << day;
    else cout << -1;
}