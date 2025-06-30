// 2025-06-30 ACM Craft
// 위상 정렬 / 그래프 이론 / 방향 비순환 그래프 / DP
// 이게 되네?로 맞은 문제
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> t(n+1);
        vector<int> indegree(n+1, 0);
        vector<vector<int>> gp(n+1);
        for(int i = 1; i<=n; i++){
            cin >> t[i];
        }

        for(int i = 0; i<k; i++){
            int x, y;
            cin >> x >> y;
            gp[x].push_back(y);
            indegree[y]++;
        }

        int w;
        cin >> w;

        vector<int> dist(n+1, 0);
        queue<int> q;
        for(int i = 1; i<=n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            if(cur == w) break;
            q.pop();
            for(auto i: gp[cur]){
                dist[i] = max(dist[i], t[cur]+dist[cur]); // 이게 힘들었다
                if(!--indegree[i]){
                    q.push(i);
                }
            }
        }

        cout << dist[w] + t[w] << '\n';
    }
}