// 2025-05-29 주사위 굴리기
// 구현 / 시뮬레이션
#include <bits/stdc++.h>
using namespace std;

int dice[4][3]; // dice[3][1]: 밑면, dice[1][1]: 윗면
int mp[20][20];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int n, m, x, y, k;

void roll_lr(int dy){
    int temp[4] = {dice[1][0], dice[1][1], dice[1][2], dice[3][1]};
    int temp2[4];
    for(int i = 0; i<4; i++){
        temp2[i] = temp[(i - dy + 4) % 4];
    }
    dice[1][0] = temp2[0];
    dice[1][1] = temp2[1];
    dice[1][2] = temp2[2];
    dice[3][1] = temp2[3];
}

void roll_ud(int dx){
    int temp[4] = {dice[0][1], dice[1][1], dice[2][1], dice[3][1]};
    int temp2[4];
    for(int i = 0; i<4; i++){
        temp2[i] = temp[(i - dx + 4) % 4];
    }
    dice[0][1] = temp2[0];
    dice[1][1] = temp2[1];
    dice[2][1] = temp2[2];
    dice[3][1] = temp2[3];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x >> y >> k;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> mp[i][j];
        }
    }

    while(k--){
        int d;
        cin >> d;

        int nx = x + dir[d-1][1];
        int ny = y + dir[d-1][0];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if(d <= 2) roll_lr(dir[d-1][0]);
        else roll_ud(dir[d-1][1]);
        
        if(mp[nx][ny] == 0) mp[nx][ny] = dice[3][1];
        else{
            dice[3][1] = mp[nx][ny];
            mp[nx][ny] = 0;
        }

        cout << dice[1][1] << '\n';

        x = nx; y = ny;
    }
}