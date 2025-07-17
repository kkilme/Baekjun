// 2025-07-18 게임 개발
// 그래프 이론 / 방향 비순환 그래프 / 위상 정렬 / DP
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> gp[501];
int times[501];
int indegree[501];
int answer[501];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i<=n; i++){
        int t, b;
        cin >> t >> b;
        times[i] = t;
        while(b != -1){
            gp[b].push_back(i);
            indegree[i]++;
            cin >> b;
        }
    }

    queue<int> q;
    for(int i = 1; i<=n; i++){
        if(indegree[i] == 0) {
            answer[i] = times[i];
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i: gp[cur]){
            answer[i] = max(answer[i], answer[cur] + times[i]);
            if(!--indegree[i]) q.push(i);
        }
    }

    for(int i = 1; i<=n; i++){
        cout << answer[i] << '\n';
    }
}