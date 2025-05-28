// 2025-05-29 특정한 최단 경로
// 그래프 이론 / 최단 경로 / 다익스트라
#include <bits/stdc++.h>
using namespace std;

int N, E;

vector<pair<int, int>> g[801];
int v1dist[801];
int v2dist[801];

void dijkstra(int start, int dist[]){
    fill(dist, dist+N+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for(auto p: g[v]){
            int nw = p.second + w;
            if(nw < dist[p.first]){
                dist[p.first] = nw;
                pq.push({nw, p.first});
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E;
    for(int i = 0; i<E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int v1, v2;
    cin >> v1 >> v2;
    
    dijkstra(v1, v1dist);
    dijkstra(v2, v2dist);

    if(v1dist[v2] == INT_MAX || v1dist[1] == INT_MAX || v1dist[N] == INT_MAX){
        cout << -1;
    } else {
        cout << v1dist[v2] + min(v1dist[1] + v2dist[N], v1dist[N] + v2dist[1]);
    }
}