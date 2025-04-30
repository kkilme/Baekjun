// 2025-04-30 ABCDE
// 그래프 이론 / 그래프 탐색 / DFS / 백트래킹
#include <bits/stdc++.h>
using namespace std;

int n, m;
int answer = 0;
vector<vector<int>> graph(2001, vector<int>());
bool used[2001];

void bt(int cur, int depth){
    if(answer == 1) return;
    if(depth == 5){
        answer = 1;
        return;
    }

    for(int i = 0; i<graph[cur].size(); i++){
        int next = graph[cur][i];
        if(!used[next]){
            used[next] = true;
            bt(next, depth+1);
            used[next] = false;
            if(answer == 1) return;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int j = 0; j<m; j++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    

    for(int i = 0; i<n; i++){
        used[i] = true;
        bt(i, 1);
        used[i] = false;
        if(answer == 1) break;
    }

    cout << answer;
}