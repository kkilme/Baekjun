// 2025-04-26 A -> B
// 그래프 이론? / 그리디 알고리즘 / 그래프 탐색? / BFS?
#include <bits/stdc++.h>
using namespace std;

int a, b;
int ans = -1;

void find(int n, int cnt){
    if (n == b){
        if (ans == -1) ans = cnt;
        else ans = min(ans, cnt);
        return;
    }
    if(n*2 <= b) find(n*2, cnt + 1);
    if((long long) n*10 + 1 <= b) find(n*10 + 1, cnt + 1);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    find(a, 1);

    cout << ans;
}