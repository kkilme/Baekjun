// 2025-05-25 뱀
// 구현 / 자료 구조 / 시뮬레이션 / 덱 / 큐
#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int mp[100][100];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int curdir = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i<k; i++){
        int x, y;
        cin >> y >> x;
        mp[y-1][x-1] = 1;
    }

    cin >> l;
    queue<pair<int, char>> q;
    for(int i = 0; i<l; i++){
        int t; char c;
        cin >> t >> c;
        q.push({t, c});
    }
    int t = 0;
    deque<pair<int, int>> snake;
    mp[0][0] = 2;
    snake.push_back({0, 0});
    while(true){
        if(!q.empty() && q.front().first == t){
            char d = q.front().second;
            q.pop();
            if(d == 'D') curdir = (5 + curdir) % 4;
            else if(d == 'L') curdir = (3 + curdir) % 4;
        }

        int ny = snake.front().second + dir[curdir][0];
        int nx = snake.front().first + dir[curdir][1];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || mp[ny][nx] == 2) break;
        if(mp[ny][nx] != 1){
            mp[snake.back().second][snake.back().first] = 0;
            snake.pop_back();          
        }
        snake.push_front({nx, ny});
        mp[ny][nx] = 2;
        t++;
    }

    cout << t+1;
}