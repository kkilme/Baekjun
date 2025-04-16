// 2025-04-16 케빈 베이컨의 6단계 법칙
// 그래프 이론 / 그래프 탐색 / BFS / 최단 경로 / 플로이드-워셜
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, answer, mn;
vector<int> v[101];
bool visited[101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mn = 2e9;
    cin >> n >> m;

    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    for(int i = 1; i<=n; i++){
        int cursum = 0;
        int dist = 1;
        fill(visited, visited+n+1, false);
        q.push(i);
        visited[i] = true;
        while (!q.empty())
        {   
            int sz = q.size();
            for(int j = 0; j<sz; j++){
                int cur = q.front();
                q.pop();
                for(auto fr: v[cur]){
                    if(!visited[fr]){
                        visited[fr] = true;
                        cursum += dist;
                        q.push(fr);
                    }
                }
            }
            dist++;
        }
        if(cursum < mn){
            mn = cursum;
            answer = i;
        }
    }

    cout << answer;
}