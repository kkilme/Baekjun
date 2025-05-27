// 2025-05-27 스도쿠
// 구현 / 백트래킹
#include <bits/stdc++.h>
using namespace std;

int board[9][9];
bool row[9][10];
bool col[9][10];
bool box[9][10];
bool clear = false;

int getBox(int x, int y){
    return x / 3 + (y / 3)*3;
}

void bt(int depth){
    if(clear) return;
    if(depth == 81){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        clear = true;
        return;
    }

    int x = depth % 9;
    int y = depth / 9;
    if(board[y][x] != 0){
        bt(depth+1);
        return;
    }
    for(int i = 1; i<=9; i++){
        if(clear) break;
        if(row[y][i] || col[x][i] || box[getBox(x, y)][i]) continue;
        row[y][i] = col[x][i] = box[getBox(x, y)][i] = true;
        board[y][x] = i;
        bt(depth+1);
        board[y][x] = 0;
        row[y][i] = col[x][i] = box[getBox(x, y)][i] = false;
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            int k;
            cin >> k;
            board[i][j] = k;
            row[i][k] = col[j][k] = box[getBox(j, i)][k] = true;
        }
    }

    bt(0);
}