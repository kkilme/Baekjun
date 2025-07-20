// 2025-07-21 웜홀
// 그래프 이론 / 벨만-포드 / 최단 경로
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, m, w;
        cin >> n >> m >> w;
        vector<vector<pair<int, int>>> gp(n+1);
        int s, e, t;
        for(int i = 0; i<m; i++){
            cin >> s >> e >> t;
            gp[s].push_back({e, t});
            gp[e].push_back({s, t});
        }

        for(int i = 0; i<w; i++){
            cin >> s >> e >> t;
            gp[s].push_back({e, -t});             
        }

        vector<int> dist(n+1, 0); // dist값을 0으로 초기화하면, 어떤 정점에서든 출발해서 음수 사이클이 있는지 판별 가능

        bool flag = false;
        for(int i = 0; i<n; i++){
            for(int k = 1; k<=n; k++){
                for(auto p: gp[k]){
                    int v = p.first;
                    int W = p.second;
                    if(dist[v] > dist[k] + W){
                        dist[v] = dist[k] + W;
                        if(i == n-1){
                            flag = true;
                            break;
                        }
                    }
                }
            }
            if(flag) break;
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}