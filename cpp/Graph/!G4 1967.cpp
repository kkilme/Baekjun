// 2025-06-01 트리의 지름
// 그래프 이론 / 그래프 탐색 / 트리 / 트리의 지름
// 아이디어를 못떠올림;
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> tree[10001];

pair<int,int> bfs(int start) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest = start;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto [next, w] : tree[cur]) {
            // dist[next] == -1: not visited
            if(dist[next] == -1) {
                dist[next] = dist[cur] + w;
                q.push(next);
                if(dist[next] > dist[farthest]) farthest = next;
            }
        }
    }
    return {farthest, dist[farthest]};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n-1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        tree[p].push_back({c, w});
        tree[c].push_back({p, w});
    }

    // 아무 점에서 가장 먼 점 찾기
    auto [u, d] = bfs(1);
    // 그 점에서 가장 먼 점까지의 거리 = 트리의 지름
    auto [v, answer] = bfs(u);

    cout << answer;
}