// 2025-05-02 맥주 마시면서 걸어가기
// 그래프 이론 / 그래프 탐색 / BFS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(103, vector<int>());
pair<int, int> mp[103];
bool visited[103];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n+=2;
        for(int i = 0; i<n; i++){
            adj[i].clear();
            visited[i] = false; 
        }
        for(int i = 0; i<n; i++){
            cin >> mp[i].first >> mp[i].second;
        }
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(abs(mp[i].first - mp[j].first) + abs(mp[i].second - mp[j].second) <= 1000){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        bool flag = false;
        while(!q.empty() && !flag){
            int cur = q.front();
            q.pop();
            for(int i = 0; i<adj[cur].size(); i++){
                if(adj[cur][i] == n-1){
                    cout << "happy\n";
                    flag = true;
                    break;
                }
                if(!visited[adj[cur][i]]){
                    visited[adj[cur][i]] = true;
                    q.push(adj[cur][i]);
                }
            }
        }
        if(!flag) cout << "sad\n";
    }
}