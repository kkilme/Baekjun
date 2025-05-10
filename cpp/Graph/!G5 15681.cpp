// 2025-05-10 트리와 쿼리
// 그래프 이론 / 그래프 탐색 / 트리 / DFS / DP? / 트리에서의 DP?
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int parent[100001];
int sz[100001];

void dfs(int node, int par){
    parent[node] = par;
    sz[node] = 1;
    for(int child: adj[node]){
        if(child == par) continue;
        dfs(child, node);
        sz[node] += sz[child];
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(r, -1);
    while(q--){
        int u;
        cin >> u;
        cout << sz[u] << '\n';
    }
}