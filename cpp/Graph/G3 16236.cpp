// 2025-06-28 아기 상어
// 구현 / 그래프 이론 / 그래프 탐색 / 시뮬레이션 / BFS
#include <bits/stdc++.h>
using namespace std;

int n;
int space[20][20];

struct Shark{
    int size = 2;
    int exp = 2;
    pair<int, int> pos;

    void addexp(){
        if(!--exp){
            exp = ++size;
        }
    }
};

Shark shark;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int k;
            cin >> k;
            if(k == 9) {
                shark.pos = {i, j};
                continue;
            }
            space[i][j] = k;
        }
    }

    int t = 0;
    int dist[20][20];
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(true){
        fill(&dist[0][0], &dist[19][20], 2e9);
        dist[shark.pos.first][shark.pos.second] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {shark.pos.first, shark.pos.second}});
        pair<int, int> target;
        int mind = 2e9;
        while(!pq.empty()){
            int d = pq.top().first;
            if(d == mind) break;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(auto dr: dir){
                int nr = r + dr[0];
                int nc = c + dr[1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(space[nr][nc] > shark.size) continue;
                int nd = dist[r][c] + 1;
                if(dist[nr][nc] > nd){
                    dist[nr][nc] = nd;
                    if(space[nr][nc] != 0 && space[nr][nc] < shark.size){
                        if(mind == 2e9){
                            mind = nd;
                            target = {nr, nc};
                        } else {
                            if(target > make_pair(nr, nc)){
                                target = {nr, nc};
                            }
                        }
                    }
                    pq.push({nd, {nr, nc}});
                }
            }
        }
        if(mind == 2e9){
            cout << t;
            break;
        }
        t += mind;
        shark.addexp();
        space[target.first][target.second] = 0;
        shark.pos.first = target.first;
        shark.pos.second = target.second;
    }
}