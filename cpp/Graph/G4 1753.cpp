// 2025-05-18 최단경로
// 그래프 이론 / 최단 경로 / 다익스트라
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[20001];
long long dist[20001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e, start;
    cin >> v >> e;
    fill(dist, dist+v+1, LONG_LONG_MAX);
    cin >> start;
    for(int i = 0; i<e; i++){
        int uu, vv, ww;
        cin >> uu >> vv >> ww;
        auto it = find_if(graph[uu].begin(), graph[uu].end(), [vv](const pair<int, int>& p) {return p.second == vv;});
        if(it == graph[uu].end()){
            graph[uu].push_back({ww, vv});
        } else {
            if(it->first > ww) it->first = ww;
        }
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int cw = -pq.top().first;
        int cv = pq.top().second;
        pq.pop();

        for(auto p: graph[cv]){
            int nw = p.first;
            int nv = p.second;
            if(dist[cv] + nw < dist[nv]){
                dist[nv] = dist[cv] + nw;
                pq.push({-dist[nv], nv}); 
            }
        }
    }

    for(int i = 1; i<=v; i++){
        if(dist[i] == LONG_LONG_MAX) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}