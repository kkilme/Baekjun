// 2025-06-26 색칠하기
// 그래프 이론 / 그래프 탐색 / BFS / DFS / 이분 그래프
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> g[1001];
        int color[1001];
        memset(color, 0, sizeof(color));
        for(int i = 0; i<m; i++){
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        bool ans = true;
        for(int i = 1; i<=n; i++){
            if(!ans) break;
            if(color[i] == 0){
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty() && ans){
                    int cur = q.front();
                    q.pop();
                    int ncolor = color[cur] == 1? 2 : 1;

                    for(auto u: g[cur]){
                        if(color[u] == color[cur]){
                            ans = false;
                            break;
                        } else if(color[u] == 0){
                            color[u] = ncolor;
                            q.push(u);
                        }
                    }
                }
            }
        }
        cout << (ans ? "possible" : "impossible") << '\n';
    }
}