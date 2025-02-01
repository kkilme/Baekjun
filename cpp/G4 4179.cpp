// 2025-02-02 불!
// 그래프 이론 / 그래프 탐색 / BFS?
// 다익스트라
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int r, c;
string map[1000];

int firemap[1000][1000];
int jmap[1000][1000];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
pair<int, int> jpos;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    for(int i = 0; i<r; i++){
        cin >> map[i];
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    queue<pair<int, int>> fires;

    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            firemap[i][j] = 2e9;
            if(map[i][j] == 'F'){
                fires.push({i, j});
                firemap[i][j] = 0;
            }
            if(map[i][j] == 'J'){
                jpos = {i, j};
            }
        }
    }

    if(jpos.first == 0 || jpos.first == r-1 || jpos.second == 0 || jpos.second == c-1){
        cout << 1;
        return 0;
    }

    while(!fires.empty()){
        pq.push({0, fires.front()});
        fires.pop();
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int t = -pq.top().first;
            pq.pop();

            for(int i = 0; i<4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(map[nx][ny] == '#') continue;
                if(firemap[nx][ny] > t+1){
                    firemap[nx][ny] = t+1;
                    pq.push({-(t+1), {nx, ny}});
                }
            }
        }   
    }

    pq.push({0, jpos});

    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int t = -pq.top().first;
        pq.pop();

        for(int i = 0; i<4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(map[nx][ny] == '#') continue;
            if(jmap[nx][ny] == 0 && firemap[nx][ny] > t+1){
                if(nx == 0 || nx == r-1 || ny == 0 || ny == c-1){
                    cout << t+2;
                    return 0;
                }
                jmap[nx][ny] = t+1;
                pq.push({-(t+1), {nx, ny}});
            }
        }
    }

    cout << "IMPOSSIBLE";
}