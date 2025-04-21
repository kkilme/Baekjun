// 2025-04-21 경로 찾기
// 그래프 이론 / 그래프 탐색 / 최단 경로 / 플로이드-워셜
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a; cin >> a;
            if(a == 1){
                adj[i].push_back(j);
            }
        }
    }

    for(int i = 0; i<n; i++){
        fill(visited.begin(), visited.end(), false);
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int j = 0; j < adj[cur].size(); j++){
                    int next = adj[cur][j];
                    if(!visited[next]){
                        visited[next] = true;
                        ans[i][next] = 1;
                        q.push(next);
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}