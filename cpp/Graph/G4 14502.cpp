// 2025-05-19 연구소
// 구현 / 그래프 이론 / 브루트포스 / 그래프 탐색 / BFS / 격자 그래프
#include <bits/stdc++.h>
using namespace std;

int n, m;
int answer;
int lab[8][8];
bool visited[8][8];
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> empties;
vector<pair<int, int>> viruses;
int emptycnt;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int k;
            cin >> k;
            lab[i][j] = k;
            if(k == 0) empties.push_back({i, j});
            if(k == 2) viruses.push_back({i, j});
        }
    }
    emptycnt = empties.size();
    for(int i = 0; i<emptycnt-2; i++){
        lab[empties[i].first][empties[i].second] = 1;
        for(int j = i+1; j<emptycnt-1; j++){
            lab[empties[j].first][empties[j].second] = 1;
            for(int k = j+1; k<emptycnt; k++){
                bool flag = false;
                int curempty = emptycnt - 3;
                lab[empties[k].first][empties[k].second] = 1;
                fill(visited[0], visited[0]+64, false);
                for(auto pos: viruses){
                    if(flag) break;
                    int x = pos.second;
                    int y = pos.first;
                    if(visited[y][x]) continue;

                    queue<pair<int, int>> q;
                    q.push({y, x});
                    visited[y][x] = true;
                    while(!q.empty() && !flag){
                        int xx = q.front().second;
                        int yy = q.front().first;
                        q.pop();
                        for(int i = 0; i<4; i++){
                            int nx = xx + dirs[i][0];
                            int ny = yy + dirs[i][1];
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && lab[ny][nx] != 1){
                                if(lab[ny][nx] == 0) curempty--;
                                if(curempty < answer){
                                    flag = true;
                                    break;
                                }
                                visited[ny][nx] = true;
                                q.push({ny, nx});
                            }
                        }
                    }
                }
                answer = max(curempty, answer);
                lab[empties[k].first][empties[k].second] = 0;
            }
            lab[empties[j].first][empties[j].second] = 0;
        }
        lab[empties[i].first][empties[i].second] = 0;
    }

    cout << answer;
}