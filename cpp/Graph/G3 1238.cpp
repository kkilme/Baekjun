// 2025-02-05 파티
// 그래프 이론 / 최단 경로 / 다익스트라
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, x;
int returndist[1002];
int godist[1002];
int curdist[1002];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;

    vector<vector<pair<int, int>>> graph(n+1);

    for(int i = 0; i<m; i++){
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
    }

    fill(returndist, returndist+n+1, 2e9);
    fill(godist, godist+n+1, 2e9);

    priority_queue<pair<int, int>> pq;

    pq.push({0, x});
    returndist[x] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int num = pq.top().second;
        pq.pop();

        if(cost > returndist[num]) continue;

        for(auto p: graph[num]){
            int nx = p.first;
            int ncost = p.second + cost;
            if(returndist[nx] > ncost){
                returndist[nx] = ncost;
                pq.push({-ncost, nx});
            }
        }
    }

    for(int i = 1; i<=n; i++){
        if(godist[i] != 2e9) continue;

        fill(curdist, curdist+n+1, 2e9);
        vector<int> prev(n+1, -1);
        pq.push({0, i});
        curdist[i] = 0;
        while(!pq.empty()){
            int cost = -pq.top().first;
            int num = pq.top().second;
            pq.pop();
            if(cost > curdist[num]) continue;

            for(auto p: graph[num]){
                int nx = p.first;
                int ncost = p.second + cost;
                if(curdist[nx] > ncost){
                    curdist[nx] = ncost;
                    prev[nx] = num;
                    pq.push({-ncost, nx});
                }
            }
        }

        int itox = curdist[x];
        for(int cur = x; cur!=-1; cur = prev[cur]){
            godist[cur] = itox - curdist[cur];
        }
    }

    int mx = 0;
    for(int i = 1; i<=n; i++){
        int cur = godist[i] + returndist[i];
        if(cur > mx) mx = cur;
    }

    cout << mx;
}