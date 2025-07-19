// 2025-07-19 음악프로그램
// 그래프 이론 / 방향 비순환 그래프 / 위상 정렬
#include <bits/stdc++.h>
using namespace std;

int indegree[1001];
vector<int> gp[1001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i<m; i++){
        int k, a, b;
        cin >> k >> a;
        while (k---1)
        {
            cin >> b;
            gp[a].push_back(b);
            indegree[b]++;
            a = b;
        }
    }

    vector<int> answer;
    queue<int> q;

    for(int i = 1; i<=n; i++){
        if(!indegree[i]){
            answer.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int k: gp[cur]){
            if(!--indegree[k]){
                answer.push_back(k);
                q.push(k);
            }
        }
    }

    if(answer.size() != n) cout << 0;
    else{
        for(int i: answer) cout << i << '\n';
    }
}