// 2025-06-22 도시 분할 계획
// 그래프 이론 / 최소 스패닝 트리
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n+1);
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    vector<bool> visited(n+1);
    q.push({0, 1});

    int mx = 0;
    int ans = 0;
    while(!q.empty()){
        int w = q.top().first;
        int v = q.top().second;
        q.pop();
        if(visited[v]) continue;
        ans += w;
        mx = max(mx, w);
        visited[v] = true;
        for(auto nb: g[v]){
            int nv = nb.first;
            if(!visited[nv]){
                q.push({nb.second, nv});
            }
        }
    }

    cout << ans - mx;
}