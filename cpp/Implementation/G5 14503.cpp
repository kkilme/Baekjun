// 2025-04-04 로봇 청소기
// 구현 / 시뮬레이션
#include <iostream>

using namespace std;

int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
char room[50][50];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> room[i][j];
        }
    }

    int answer = 0;
    while (true)
    {
        if(room[r][c] == '0'){
            room[r][c] = '2';
            answer++;
        }
        bool cango = false;
        int nx, ny;
        for(int i = 0, j = d; i<4; i++){
            j = j == 0 ? 3 : j-1;
            nx = c + dir[j][0];
            ny = r + dir[j][1];
            if(ny > 0 && ny < n && nx > 0 && nx < m){
                if(room[ny][nx] == '0'){
                    cango = true;
                    d = j;
                    break;
                }
            }
        }
        if(cango){
            r = ny; c = nx;
        } else {
  
            int back;
            if(d < 2) back = d+2;
            else back = d - 2;
            if(room[r+dir[back][1]][c+dir[back][0]] == '1'){
                break;
            } else {
                r += dir[back][1]; c += dir[back][0];
            }
            
        }
    }
    cout << answer;
    
}