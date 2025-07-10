// 2025-07-11 드래곤 커브
// 구현 / 시뮬레이션
// (x, y)를 원점 기준 시계방향으로 90도 회전 -> (y, -x)
// 근데 배열은 y좌표가 밑으로 증가하므로 (-y, x)
// 점 (x0, y0)을 기준으로 회전 시 (x0 - (y1 - y0), y0 + (x1 - x0))
#include <bits/stdc++.h>
using namespace std;

int n;
bool grid[101][101];
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

void paint(int x, int y, int d, int g){
    vector<pair<int, int>> points = {{x, y}, {x + dir[d][0], y + dir[d][1]}};
    for(auto p: points){
        grid[p.second][p.first] = true;
    }

    while(g--){
        int originX = points[points.size()-1].first;
        int originY = points[points.size()-1].second;
        int sz = points.size();
        for(int i = sz-1; i>=0; i--){
            int cx = points[i].first;
            int cy = points[i].second;

            int nx = originX - (cy - originY);
            int ny = originY + (cx - originX);
            grid[ny][nx] = true;
            points.push_back({nx, ny});
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        paint(x, y, d, g);
    }

    int ans = 0;
    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            if(grid[i][j] && grid[i+1][j] && grid[i][j+1] && grid[i+1][j+1]) ans++;
        }
    }
    cout << ans;
}