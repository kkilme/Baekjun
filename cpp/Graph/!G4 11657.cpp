// 2025-06-23 타임머신
// 그래프 이론 / 최단 경로 / 벨만-포드
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> gp[501];
long long dist[501];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        gp[u].push_back({v, w});
    }

    fill(dist, dist+501, 2e9);
    dist[1] = 0;
    bool flag = false;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){ // gp[i]의 이웃이 아니라, 그냥 모든 간선을 확인해야 함
            for(auto p: gp[j]){
                int v = p.first;
                int w = p.second;
                if(dist[j] != 2e9 && dist[v] > dist[j] + w){
                    dist[v] = dist[j] + w;
                    if(i == n) flag = true;
                }
            }
        }
    }

    if(flag) cout << -1;
    else{
        for(int i = 2; i<=n; i++){
            int d = dist[i];
            if(d == 2e9) cout << -1 << '\n';
            else cout << d << '\n';
        }
    }
}