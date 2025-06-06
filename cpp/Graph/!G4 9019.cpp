// 2025-06-06 DSLR
// 그래프 이론 / 그래프 탐색 / BFS / 역추적
// 스트링 + 연산은 효율이 좋지 않으므로 역추적을 위한 배열을 사용해야 한다 
#include <bits/stdc++.h>
using namespace std;

int t, a, b;
bool visited[10000];
pair<int, char> from[10000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> a >> b;
        fill(visited, visited+10000, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, a});
        visited[a] = true;
        from[a] = {-1, ' '};

        while(!pq.empty()){
            int cnt = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if(cur == b) break;

            int nxts[4];
            char cmds[4] = {'D', 'S', 'L', 'R'};

            nxts[0] = (cur * 2) % 10000;
            nxts[1] = (cur + 9999) % 10000;

            int l = cur / 1000;
            int r = cur % 1000;
            nxts[2] = r * 10 + l;

            l = cur / 10;
            r = cur % 10;
            nxts[3] = r * 1000 + l;

            for(int i = 0; i<4; i++){
                int nxt = nxts[i];
                if(!visited[nxt]){
                    visited[nxt] = true;
                    from[nxt] = {cur, cmds[i]};
                    pq.push({cnt+1, nxt}); 
                }
            }
        }

        string ans;
        for(int i = b; from[i].first != -1; i = from[i].first){
            ans += from[i].second;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}