// 2025-06-10 탈출
// 그래프 이론 / 그래프 탐색 / BFS / 격자 그래프
// 다익스트라 풀이
#include <bits/stdc++.h>
using namespace std;

int r, c;
int Stime[50][50];
int watertime[50][50];
string mp[50];
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> Spos;
    pair<int, int> Wpos;
    pair<int, int> Dpos;

    vector<pair<int, int>> waters;
    cin >> r >> c;
    for(int i = 0; i<r; i++){
        string s;
        cin >> s;
        for(int j = 0; j<c; j++){
            if(s[j] == 'D') Dpos = {i, j};
            if(s[j] == 'S') Spos = {i, j};
            if(s[j] == '*') waters.push_back({i, j});
        }
        mp[i] = s;
    }
    
    fill(&Stime[0][0], &Stime[49][50], 2e9);
    fill(&watertime[0][0], &watertime[49][50], 2e9);
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<>> q;
    for(auto p: waters){
        q.push({0, p});
        watertime[p.first][p.second] = 0;
    }
    while(!q.empty()){
        int t = q.top().first;
        int y = q.top().second.first;
        int x = q.top().second.second;
        q.pop();

        for(auto d: dirs){
            int ny = y + d[0];
            int nx = x + d[1];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if(mp[ny][nx] == 'X' || mp[ny][nx] == 'D') continue;
            if(watertime[ny][nx] > t+1){
                watertime[ny][nx] = t+1;
                q.push({t+1, {ny, nx}});
            }
        }

    }
    q.push({0, Spos});
    Stime[Spos.first][Spos.second] = 0;

    while(!q.empty()){
        int t = q.top().first;
        int y = q.top().second.first;
        int x = q.top().second.second;
        q.pop();

        for(auto d: dirs){
            int ny = y + d[0];
            int nx = x + d[1];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if(mp[ny][nx] == 'X') continue;
            if(Stime[ny][nx] > t+1 && watertime[ny][nx] > t+1){
                Stime[ny][nx] = t+1;
                q.push({t+1, {ny, nx}});
            }
        }
    } 

    if(Stime[Dpos.first][Dpos.second] == 2e9) cout << "KAKTUS";
    else cout << Stime[Dpos.first][Dpos.second];
}