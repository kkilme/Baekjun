// 2025-06-20 숨바꼭질 4
// 그래프 이론 / 그래프 탐색 / BFS? / 역추적
#include <bits/stdc++.h>
using namespace std;

int n, k;
int path[100001];
int dist[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

void push(int t, int x, int prv){
    if(x < 0 || x > 100000) return;
    if(dist[x] > t){
        dist[x] = t;
        path[x] = prv;
        q.push({t, x});
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    if(k <= n){
        cout << n-k << '\n';
        for(int i = n; i>=k; i--){
            cout << i << ' ';
        }
        return 0;
    }

    fill(dist, dist+100001, 2e9);
    fill(path, path+100001, -1);
    dist[n] = 0;
    q.push({0, n});
    while(!q.empty()){
        int curt = q.top().first;
        int curx = q.top().second;
        q.pop();
        if(curx == k) break;
        push(curt+1, curx*2, curx);
        push(curt+1, curx-1, curx);
        push(curt+1, curx+1, curx);
    }

    vector<int> p;
    int i = k;
    while(i != -1){
        p.push_back(i);
        i = path[i];
    }
    reverse(p.begin(), p.end());
    cout << dist[k] << '\n';
    for(int i: p){
        cout << i << ' ';
    }
}