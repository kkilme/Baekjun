// 2025-07-15 말이 되고픈 원숭이
// 그래프 이론 / 그래프 탐색 / BFS / 격자 그래프
#include <bits/stdc++.h>
using namespace std;

int k, w, h;
int answer = 2e9;
bool world[201][201];
bool realvisited[201][201];
int visited[201][201];
vector<pair<int,int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int,int>> horsedirs {{-2, -1}, {-1, -2}, {1, 2}, {2, 1}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}};

struct entry{
    int r;
    int c;
    int cnt;
    int k;
};

void pushq(queue<entry>& q, entry& e, vector<pair<int,int>>& dir, int nxtk){
    for(auto d: dir){
        int nr = e.r + d.first;
        int nc = e.c + d.second;
        if(nr < 0 || nr >= h || nc < 0 || nc >= w || world[nr][nc]) continue;
        if(nr == h-1 && nc == w-1){
            answer = min(answer, e.cnt+1);
            continue;
        }
        if(realvisited[nr][nc] && visited[nr][nc] >= nxtk) continue;
        realvisited[nr][nc] = true;
        visited[nr][nc] = nxtk;
        q.push({nr, nc, e.cnt+1, nxtk});
    }    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> w >> h;
    if(w == 1 && h == 1){
        cout << 0;
        return 0;
    }
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            cin >> world[i][j];
        }
    }

    queue<entry> q;
    q.push({0, 0, 0, k});
    realvisited[0][0] = true;
    visited[0][0] = k;
    while(!q.empty()){
        entry e = q.front();
        q.pop();
        if(e.k < visited[e.r][e.c] || e.cnt - 1 >= answer) continue;
        if(e.k > 0){
            pushq(q, e, horsedirs, e.k-1);
        }
        pushq(q, e, dirs, e.k);
    }

    if(answer == 2e9) answer = -1;
    cout << answer;
}