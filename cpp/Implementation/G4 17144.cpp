// 2025-06-02 미세먼지 안녕!
// 구현 / 시뮬레이션
#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int room[50][50][2];
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> t;
    int cleanerUp = -1, cleanerDown = -1;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            int k;
            cin >> k;
            room[i][j][1] = room[i][j][0] = k;
            if(k == -1){
                if(cleanerUp == -1){
                    cleanerUp = i;
                } else {
                    cleanerDown = i;
                }
            }
        }
    }

    while(t--){
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                room[i][j][1] = room[i][j][0];
            }
        }
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(room[i][j][1] > 0){
                    int cnt = 0;
                    for(auto [x, y]: dir){
                        int nx = j + x;
                        int ny = i + y;
                        if(nx >= 0 && nx < c && ny >= 0 && ny < r && room[ny][nx][0] != -1){
                            cnt++;
                            room[ny][nx][0] += room[i][j][1] / 5;                                
                        }
                    }
                    room[i][j][0] -= (room[i][j][1] / 5) * cnt;
                }
            }
        }
        for(int i = cleanerUp-1; i>0; i--) room[i][0][0] = room[i-1][0][0];
        for(int j = 0; j < c-1; j++) room[0][j][0] = room[0][j+1][0];
        for(int i = 0; i < cleanerUp; i++) room[i][c-1][0] = room[i+1][c-1][0];
        for(int j = c-1; j > 1; j--) room[cleanerUp][j][0] = room[cleanerUp][j-1][0];
        room[cleanerUp][1][0] = 0;

        for(int i = cleanerDown+1; i < r-1; i++) room[i][0][0] = room[i+1][0][0];
        for(int j = 0; j < c-1; j++) room[r-1][j][0] = room[r-1][j+1][0];
        for(int i = r-1; i > cleanerDown; i--) room[i][c-1][0] = room[i-1][c-1][0];
        for(int j = c-1; j > 1; j--) room[cleanerDown][j][0] = room[cleanerDown][j-1][0];
        room[cleanerDown][1][0] = 0;
    }
    int answer = 0;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(room[i][j][0] > 0) answer += room[i][j][0];
        }
    }
    cout << answer;
}