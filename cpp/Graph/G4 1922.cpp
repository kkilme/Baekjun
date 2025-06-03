// 2025-06-04 네트워크 연결
// 그래프 이론 / 최소 스패닝 트리
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> g[1001];
bool visited[1001];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        if(u == v) continue;
        
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(auto v: g[1]) pq.push({v.second, v.first});
    visited[1] = true;
    int answer = 0;
    while (!pq.empty())
    {
        int v = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(visited[v]) continue;
        visited[v] = true;
        answer += w;
        for(auto vv: g[v]){
            if(!visited[vv.first]) pq.push({vv.second, vv.first});
        }
    }

    cout << answer;
    
}