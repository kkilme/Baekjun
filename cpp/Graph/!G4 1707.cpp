// 2025-05-31 이분 그래프
// 그래프 이론 / 그래프 탐색 / BFS / DFS / 이분 그래프
// 이분 그래프: 인접한 정점을 서로 다른 색으로 칠했을 때 모든 정점을 두 가지 색으로 칠할 수 있는 그래프
#include <bits/stdc++.h>
using namespace std;

int color[20001];
vector<int> g[20001];
bool answer;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int V, E;
        cin >> V >> E;
        answer = true;

        fill(color, color+V+1, 0);
        fill(g, g+V+1, vector<int>());

        for(int i = 0; i<E; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i = 1; i<=V; i++){
            if(!answer) break;
            if(color[i] == 0){
                queue<int> q;
                q.push(i);
                color[i] = 1;

                while(!q.empty() && answer){
                    int cur = q.front();
                    q.pop();

                    int ncolor = color[cur] == 1 ? 2 : 1;
                    for(auto v: g[cur]){
                        if(color[v] == color[cur]){
                            answer = false;
                            break;
                        }
                        if(color[v] == 0){
                            color[v] = ncolor;
                            q.push(v);
                        }
                    }
                }
            }
        }

        cout << (answer ? "YES" : "NO") << '\n';
    }
}