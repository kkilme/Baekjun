// 2025-07-11 최소비용 구하기 2
// 그래프 이론 / 최단 경로 / 다익스트라 / 역추적
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> buses(1001);
int dist[1001];
int prv[1001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        auto it = find_if(buses[u].begin(), buses[u].end(), [v](const pair<int, int>& p) {return p.first == v;});
        if(it == buses[u].end()){
            buses[u].push_back({v, w});
        } else {
            if(it->second > w) it->second = w;
        }
    }

    int start, dest;
    cin >> start >> dest;

    fill(dist, dist+1001, 2e9);
    dist[start] = 0;
    prv[start] = -1;

    priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for(auto e: buses[v]){
            int u = e.first;
            int nw = e.second;
            if(dist[u] > w + nw){
                dist[u] = w + nw;
                pq.push({w + nw, u});
                prv[u] = v;
            }
        }
    }
    
    vector<int> path;
    path.push_back(dest);
    int nxt = prv[dest];
    while(nxt != -1){
        path.push_back(nxt);
        nxt = prv[nxt];
    }
    reverse(path.begin(), path.end());
    cout << dist[dest] << '\n' << path.size() << '\n';
    for(auto v: path){
        cout << v << ' ';
    }
}