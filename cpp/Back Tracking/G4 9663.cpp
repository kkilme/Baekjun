// 2024-12-29 N-Queen
// 백트래킹
#include <iostream>

using namespace std;

int board[15];
int n, answer=0;

bool check(int row, int col){
    for(int i = 0; i<n; i++){
        if(board[i] != -1){
            if(col == board[i]) return false;
            if(abs(row - i) == abs(board[i] - col)) return false; 
        }
    }
    return true;
}

void dfs(int depth){
    if(depth == n){
        answer++;
        return;
    }

    for(int i = 0; i<n; i++){
        if(check(depth, i)){
            board[depth] = i;
            dfs(depth+1);
            board[depth] = -1;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<15; i++){
        board[i] = -1;
    }
    dfs(0);
    cout << answer;
}