// 2025-04-23 트리의 부모 찾기
// 그래프 이론 / 그래프 탐색 / 트리 / DFS / BFS
// 의도된 풀이로 푼 것 같지는 않음
#include <bits/stdc++.h>
using namespace std;

int parent[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> gph(n+1);
    vector<int> cnt(n+1, 0);

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        cnt[a]++; cnt[b]++;
        gph[a].push_back(b);
        gph[b].push_back(a);
    }

    queue<int> q;
    for(int i = 2; i <= n; i++){
        if(cnt[i] == 1){
            q.push(i);
        }
    }

    // 내 풀이 : leaf 노드에서 부모 노드로 가는 방향으로 탐색
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int n: gph[node]){
            if(parent[n] == 0){
                cnt[n]--;
                parent[node] = n;
                if(cnt[n] == 1 && n!=1) q.push(n);
                break;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        cout << parent[i] << '\n';
    }

}

/* 아마 의도된 풀이: 부모에서 leaf 노드로 가는 방향으로 탐색
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> adj(N+1);
    for(int i = 0; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(N+1, 0);
    vector<bool> visited(N+1, false);
    queue<int> q;

    // 루트 = 1
    visited[1] = true;
    q.push(1);

    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // 2번 노드부터 부모 출력
    for(int i = 2; i <= N; i++){
        cout << parent[i] << "\n";
    }
    return 0;
}

*/