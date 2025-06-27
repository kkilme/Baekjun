// 2025-06-27 줄 세우기
// 위상 정렬 / 그래프 이론 / 방향 비순환 그래프
// 위상 정렬: 사이클이 없는 방향 그래프(DAG = Direct Acyclic Graph)의 모든 노드를 '방향성에 거스르지 않도록 순서대로 나열'하는 정렬

/*
시작: 진입차수가 0인 노드를 큐에 넣는다.
큐가 빌 때까지 다음의 과정을 반복한다.
1. 큐에서 원소를 꺼내 해당 노드에서 나가는 간선을 그래프에서 제거
2. 새롭게 진입차수가 0이 된 노드를 큐에 삽입
*/

// 모든 원소를 방문하기 전 큐가 비면 사이클이 존재
// O(V+E)
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> gp[32001];
int indegree[32001];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    while(m--){
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto i: gp[cur]){
            if(--indegree[i] == 0){
                q.push(i);
            }
        }
    }

    for(auto i: ans){
        cout << i << ' ';
    }
}