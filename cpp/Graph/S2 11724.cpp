// 2025-02-26 연결 요소의 개수
// 그래프 이론 / 그래프 탐색 / 너비 우선 탐색 / 깊이 우선 탐색
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);

    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int connected = 0;
    vector<bool> visited(n+1, false);

    for(int i = 1; i<=n; i++){
        if(visited[i]) continue;
        connected++;
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int next : graph[cur]){
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }
    }

    cout << connected;
}