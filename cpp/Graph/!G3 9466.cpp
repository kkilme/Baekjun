// 2025-07-03 텀 프로젝트
// 그래프 이론? / 그래프 탐색? / DFS?
// 탐색을 시작한 곳이 사이클의 시작이 아닐 경우,
// 즉 탐색 도중에 작은 크기의 사이클이 존재하는 것도 판별해내야 시간초과를 막을 수 있음
#include <bits/stdc++.h>
using namespace std;

int selection[100001];
bool complete[100001];
int group[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        memset(selection, 0, sizeof(selection));
        memset(complete, false, sizeof(complete));
        memset(group, 0, sizeof(group));
        int n;
        cin >> n;
        for(int i = 1; i<=n; i++){
            cin >> selection[i];
        }
        
        int curg = 1;
        int done = 0;
        for(int i = 1; i<=n; i++){
            if(complete[group[i]]) continue;
            int nxt = selection[i];
            while(!complete[group[nxt]] && group[nxt] != curg){
                group[nxt] = curg;
                nxt = selection[nxt];
            }
            if(group[nxt] == curg){
                int st = nxt;
                int nt = selection[st];
                int cnt = 1;
                while(nt != st){
                    cnt++;
                    nt = selection[nt];
                }
                done += cnt;
            }
            complete[curg++] = true;
        }

        cout << n - done << '\n';
    }
}