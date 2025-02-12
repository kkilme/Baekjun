// 2025-02-13 벽 부수고 이동하기
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<string> map(n);

    for(int i = 0; i<n; i++){
        cin >> map[i];
    }

    vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    queue<pair<int, pair<int, int>>> q;
    
    q.push({0, {0, 0}});
    int answer = 1;

    while (!q.empty())
    {   
        int size = q.size();
        for(int i = 0; i<size; i++){
            int used = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if(x == n-1 && y == m-1){
                cout << answer;
                return 0;
            }

            for(int j = 0; j<4; j++){
                int nx = x + dir[j][0];
                int ny = y + dir[j][1];
                int used2 = used;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                if(map[nx][ny] == '0' && !visit[nx][ny][used2]){
                    visit[nx][ny][used2] = true;
                    q.push({used2, {nx, ny}});
                } else if(map[nx][ny] == '1' && !visit[nx][ny][used2] && used2 == 0) {
                    used2 = 1;
                    visit[nx][ny][used2] = true;
                    q.push({used2, {nx, ny}});
                }
            }
        }
        answer++;
    }

    cout << -1;
    
}