// 2025-06-26 스도쿠
// 구현 / 백트래킹
// 2580과 거의 동일
#include <bits/stdc++.h>
using namespace std;

bool done;
int sudoku[9][9];
bool row[9][10];
bool col[9][10];
bool box[9][10];

int getbox(int r, int c){
    return (r/3) * 3 + (c/3);
}

void bt(int r, int c){
    if(done) return;
    if(r == 9){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                cout << sudoku[i][j];
            }
            cout << '\n';
        }
        done = true;
        return;
    }
    int nr = c == 8? r+1 : r;
    int nc = c == 8? 0 : c+1;

    if(sudoku[r][c] != 0){
        bt(nr, nc);
        return;
    }

    for(int i = 1; i<=9; i++){
        if(row[r][i] || col[c][i] || box[getbox(r, c)][i]) continue;
        row[r][i] = col[c][i] = box[getbox(r, c)][i] = true;
        sudoku[r][c] = i;
        bt(nr, nc);
        sudoku[r][c] = 0;
        row[r][i] = col[c][i] = box[getbox(r, c)][i] = false;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i<9; i++){
        string s;
        cin >> s;
        for(int j = 0; j<9; j++){
            int cur = s[j] - '0';
            sudoku[i][j] = cur;
            if(cur != 0){
                row[i][cur] = true;
                col[j][cur] = true;
                box[getbox(i,j)][cur] = true;
            }
        }
    }

    bt(0, 0);
}