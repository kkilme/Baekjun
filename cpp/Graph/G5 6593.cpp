// 2025-05-15 상범 빌딩
// 그래프 이론 / 그래프 탐색 / BFS / 격자 그래프
#include <bits/stdc++.h>
using namespace std;

int l, r, c;
string buil[30][30];
bool visited[30][30][30] = {false, };
int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        cin >> l >> r >> c;
        if(l+r+c == 0) break;

        fill(&visited[0][0][0], &visited[0][0][0] + 30*30*30, false);

        int sx, sy, sz, ex, ey, ez;
        bool sfound, efound;
        sfound = efound = false;
        for(int i = 0; i<l; i++){
            for(int j = 0; j<r; j++){
                cin >> buil[i][j];
                if(!sfound || !efound){
                    for(int k = 0; k<c; k++){
                        if(buil[i][j][k] == 'S'){
                            sx = k; sy = j; sz = i; sfound = true;
                        } else if(buil[i][j][k] == 'E'){
                            ex = k; ey = j; ez = i; efound = true;
                        }
                    }
                }
            }
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({sz, {sy, sx}});
        visited[sz][sy][sx] = true;
        bool found = false;
        int ans = 0;
        while(!q.empty() && !found){
            ans++;
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                if(found) break;
                int x,y,z;
                x = q.front().second.second;
                y = q.front().second.first;
                z = q.front().first;
                q.pop();
                for(int j = 0; j<6; j++){
                    int nx, ny, nz;
                    nx = x + dir[j][2];
                    ny = y + dir[j][1];
                    nz = z + dir[j][0];

                    if(nx >= 0 && nx < c && ny >= 0 && ny < r && nz >= 0 && nz < l && !visited[nz][ny][nx]){
                        if(buil[nz][ny][nx] == 'E'){
                            cout << "Escaped in " << ans << " minute(s).\n";
                            found = true; break;
                        } else if(buil[nz][ny][nx] == '.'){
                            q.push({nz, {ny, nx}});
                            visited[nz][ny][nx] = true;
                        }
                    }
                }
            }
        }
        if(!found) cout << "Trapped!\n";
    }

}