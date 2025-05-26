// 2025-05-23 플로이드
// 그래프 이론 / 최단 경로 / 플로이드-워셜(의도)(O(n^3))
// 다익스트라로 품;;(이 문제에서 O(nmlogn))
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> g[100001];
int dists[101][101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        auto it = find_if(g[u].begin(), g[u].end(), [&v](pair<int, int> p){ return p.first == v;});
        if(it == g[u].end()){
            g[u].push_back({v, w});
        } else {
            if(it->second > w) it->second = w;
        }
    }

    for(int i = 1; i<=n; i++){
        fill(dists[i], dists[i]+n+1, INT_MAX);
        dists[i][i] = 0;
    }

    for(int i = 1; i<=n; i++){
        priority_queue<pair<int, int>> pq;
        pq.push({0, i});
        while(!pq.empty()){
            int cw = -pq.top().first;
            int cv = pq.top().second;
            pq.pop();

            for(auto p: g[cv]){
                int nw = p.second;
                int nv = p.first;
                if(dists[i][nv] > cw + nw){
                    dists[i][nv] = cw + nw;
                    pq.push({-dists[i][nv], nv});
                }
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(dists[i][j] == INT_MAX) cout << "0 ";
            else cout << dists[i][j] << ' ';
        }
        cout << '\n';
    }

}
/* 플로이드 워셜
int n, m;
int dists[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    // 거리 배열 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dists[i][j] = 0;
            else dists[i][j] = INT_MAX;
        }
    }

    // 간선 정보 입력
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (dists[u][v] > w) dists[u][v] = w; // 여러 간선 중 최소값만 저장
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dists[i][k] != INT_MAX && dists[k][j] != INT_MAX) {
                    if (dists[i][j] > dists[i][k] + dists[k][j]) {
                        dists[i][j] = dists[i][k] + dists[k][j];
                    }
                }
            }
        }
    }

    // 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dists[i][j] == INT_MAX) cout << "0 ";
            else cout << dists[i][j] << ' ';
        }
        cout << '\n';
    }
}
*/