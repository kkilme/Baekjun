// 2025-02-23 DFS와 BFS
// 그래프 이론 / 그래프 탐색 / BFS / DFS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n+1);
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> visited(n+1, 0);
    vector<int> st;

    st.push_back(v);

    while(!st.empty()){
        int cur = st.back();
        st.pop_back();
        if(visited[cur]) {
            continue;
        }
        visited[cur] = 1;
        cout << cur << ' ';
        for(int i = graph[cur].size()-1; i>=0; i--){
            int next = graph[cur][i];
            if(visited[next] == 0){
                st.push_back(next);
            }
        }
    }

    cout << '\n';

    fill(visited.begin(), visited.end(), 0);

    vector<int> q;
    q.push_back(v);

    while(!q.empty()){
        int cur = q.front();
        q.erase(q.begin());
        if(visited[cur]) {
            continue;
        }
        visited[cur] = 1;
        cout << cur << ' ';
        for(int i = 0; i<graph[cur].size(); i++){
            int next = graph[cur][i];
            if(visited[next] == 0){
                q.push_back(next);
            }
        }
    }
}