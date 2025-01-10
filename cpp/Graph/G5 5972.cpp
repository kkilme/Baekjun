// 2025-01-11 택배 배송
// 그래프 이론 / 최단 경로 / 다익스트라
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;

unordered_map<int, int> dists;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
unordered_map<int, vector<pair<int, int>>> adjacency;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i<=m; i++){
        int a, b, k;
        cin >> a >> b >> k;

        adjacency[a].push_back(make_pair(b, k));
        adjacency[b].push_back(make_pair(a, k));
    }

    for(int i = 1; i<=50001; i++){
        dists[i] = 1e9;
    }
    dists[1] = 0;
    pq.push(make_pair(0,1));

    while(!pq.empty()){
        int curdist = pq.top().first;
        int curnode = pq.top().second;
        pq.pop();
        if(dists[curnode] < curdist) continue;
        for(int i = 0; i < adjacency[curnode].size(); i++){
            int nextnode = adjacency[curnode][i].first;
            int nextdist = adjacency[curnode][i].second;

            if(dists[nextnode] > dists[curnode] + nextdist){
                dists[nextnode] = dists[curnode] + nextdist;
                pq.push(make_pair(dists[nextnode], nextnode));
            }
        }
        
    }

    cout << dists[n];

}