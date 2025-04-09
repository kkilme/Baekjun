// 2025-04-10 파이프 옮기기 1
// 그래프 이론 / 그래프 탐색
// DP로 푸는게 나을듯
#include <iostream>
#include <queue>
#define Q queue<pair<pair<int, int>, int>>
using namespace std;

int n;
bool house[16][16];

int ans;

void right(Q &q, int r, int c){
    if(c + 1 < n && !house[r][c + 1]){
        if(r == n - 1 && c + 1 == n - 1){
            ans++;
            return;
        }
        q.push({{r, c + 1}, 0});
    }
}

void down(Q &q, int r, int c){
    if(r + 1 < n && !house[r + 1][c]){
        if(r + 1 == n - 1 && c == n - 1){
            ans++;
            return;
        }
        q.push({{r + 1, c}, 1});
    }
}

void diagonal(Q &q, int r, int c){
    if(r + 1 < n && c + 1 < n && !house[r + 1][c] && !house[r][c + 1] && !house[r + 1][c + 1]){
        if(r + 1 == n - 1 && c + 1 == n - 1){
            ans++;
            return;
        }
        q.push({{r + 1, c + 1}, 2});
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> house[i][j];
        }
    }

    Q q;
    q.push({{0, 1}, 0});
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dir = q.front().second;
        q.pop();

        if(dir == 0){
            right(q, r, c);
            diagonal(q, r, c);
        }else if(dir == 1){
            down(q, r, c);
            diagonal(q, r, c);
        }else if(dir == 2){
            diagonal(q, r, c);
            down(q, r, c);
            right(q, r, c);
        }
    }
    cout << ans;
}