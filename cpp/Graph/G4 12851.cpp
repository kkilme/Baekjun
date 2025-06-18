// 2025-06-18 숨바꼭질 2
// 그래프 이론 / 그래프 탐색 / BFS?
#include <bits/stdc++.h>
using namespace std;

int n, k;
int dist[100001];
int cnts[100001];
int mint = -1;
int cnt = 1;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> q;

void push(int t, int x, int prev){
    if(x >= 0 && x <= 100000 && dist[x] >= t){
        if(dist[x] == t) cnts[x] += cnts[prev];
        else{
            dist[x] = t;
            cnts[x] = cnts[prev];
            q.push({t, x});
        }
    }
}

int main(){

    cin >> n >> k;

    if(n == k){
        cout << "0\n1";
        return 0;
    } else if (k < n){
        cout << n - k << '\n' << 1;
        return 0;
    }

    fill(dist, dist+100001, 2e9);
    dist[n] = 0;
    cnts[n] = 1;
    push(1, n*2, n);
    push(1, n-1, n);
    push(1, n+1, n);

    while(!q.empty()){
        int t = q.top().first;
        int x = q.top().second;
        q.pop();
        if(mint != -1 && t > mint) break;
        if(x == k){
            mint = t;
            continue;
        }
        push(t+1, x*2, x);
        push(t+1, x-1, x);
        push(t+1, x+1, x);
    }

    cout << mint << '\n' << cnts[k];

}