// 2025-07-16 사다리 조작
// 구현 / 브루트포스 / 백트래킹
#include <bits/stdc++.h>
using namespace std;

bool complete;
int n, m, h;
bool ladders[31][11][11];

int play(int i){
    for(int j = 1; j<=h; j++){
        if(i != n && ladders[j][i][i+1]) i++;
        else if(i != 1 && ladders[j][i][i-1]) i--;
    }
    return i;
}

bool check(){
    for(int i = 1; i<=n; i++){
        if(play(i) != i) return false;
    }
    return true;
}

void bt(int depth, int startrow){
    if(complete) return;
    if(depth == 0){
        complete = check();
        return;
    }

    for(int i = startrow; i<=h; i++){
        for(int j = 1; j<n; j++){
            if(!ladders[i][j][j+1]){
                ladders[i][j][j+1] = ladders[i][j+1][j] = true;
                bt(depth-1, i);
                ladders[i][j][j+1] = ladders[i][j+1][j] = false;
            }
        }
    }
}

void solve(int cnt){
    bt(cnt, 0);
    if(complete) cout << cnt;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;
    for(int i = 0; i<m; i++){
        int r, c;
        cin >> r >> c;
        ladders[r][c][c+1] = ladders[r][c+1][c] = true;
    }

    for(int i = 0; i<=3 && !complete; i++){
        solve(i);
    }

    if(!complete) cout << -1;
}