// 2025-01-23 알파벳
// 백트래킹 / 그래프 이론 / 그래프 탐색 / DFS
#include <iostream>

using namespace std;

int answer = 0;
char board[20][20];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int r, c;

void backtrack(int x, int y, bool used[], int depth){
    answer = max(answer, depth);
    
    for(int i = 0; i<4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

        char cur = board[nx][ny];
        if(used[cur - 'A']) continue;

        used[cur - 'A'] = true;
        backtrack(nx, ny, used, depth+1);
        used[cur - 'A'] = false;

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin >> board[i][j];
        }
    }

    bool used[26] = {false,};

    used[board[0][0] - 'A'] = true;
    backtrack(0, 0, used, 1);

    cout << answer;
}