// 2025-01-17 인구이동
// 구현 / 그래프 이론 / 그래프 탐색 / 시뮬레이션 / BFS
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, l, r;
int world[51][51];
int visit[51][51];
int direction[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool bfs(int start_x, int start_y){
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    
    vector<pair<int, int>> united;
    united.push_back({start_x, start_y});
    int sum = world[start_x][start_y];

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(visit[x][y]) continue;
        visit[x][y] = 1;

        for(int i=0; i<4; i++){
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visit[nx][ny]) continue;
            
            int diff = abs(world[x][y] - world[nx][ny]);
            if(diff >= l && diff <= r){
                
                q.push({nx, ny});
                if(find(united.begin(), united.end(), make_pair(nx, ny)) == united.end()){
                    united.push_back({nx, ny});
                    sum += world[nx][ny];
                }
            }
        }
    }

    bool changed = false;

    int avg = sum / united.size();
    for(pair<int, int> p : united){
        if(world[p.first][p.second] != avg) {
            world[p.first][p.second] = avg;
            changed = true;
        }
    }
    
    return changed;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> world[i][j];
        }
    }

    int day = 0;
    bool moved = true;
    while (moved)
    {   
        moved = false;
        memset(visit, 0, sizeof(visit));

        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visit[i][j]){
                    moved |= bfs(i, j);
                }
            }
        }

        if(moved) day++;
        // cout << "day: " << day << '\n';
        // for(int i = 0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << world[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    cout << day;
    
}