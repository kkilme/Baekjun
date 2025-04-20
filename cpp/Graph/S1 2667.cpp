// 2025-04-20 단지번호붙이기
// 그래프 이론 / 그래프 탐색 / DFS / BFS
#include <bits/stdc++.h>
using namespace std;

int n;
string mp[26];
bool visited[26][26];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> mp[i];
    }
    vector<int> cnts;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(mp[i][j] == '1' && !visited[i][j]){
                cnts.push_back(0);
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    cnts.back()++;
                    for(int k = 0; k < 4; k++){
                        int nr = r + (k == 0) - (k == 1);
                        int nc = c + (k == 2) - (k == 3);
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && mp[nr][nc] == '1' && !visited[nr][nc]){
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }

    sort(cnts.begin(), cnts.end());
    cout << cnts.size() << "\n";
    for(int i = 0; i < cnts.size(); i++){
        cout << cnts[i] << "\n";
    }
}