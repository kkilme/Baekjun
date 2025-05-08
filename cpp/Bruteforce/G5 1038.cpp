// 2025-05-08 감소하는 수
// 브루트포스 / 백트래킹?
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[1000001];

int digit(int n){
    if(n == 0) return 1;
    int cnt = 0;
    while(n > 0){
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(arr, arr + 1000001, -1);
    int n;
    cin >> n;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for(int i = 0; i<=9; i++){
        pq.push({i, i});
    }
    int i = 0;
    while(!pq.empty()){
        ll cur = pq.top().first;
        int first = pq.top().second;
        pq.pop();
        arr[i++] = cur;
        for(int j = first+1; j<10; j++){
            pq.push({cur + pow(10, digit(cur)) * j, j});
        }
    }
    cout << arr[n];
}