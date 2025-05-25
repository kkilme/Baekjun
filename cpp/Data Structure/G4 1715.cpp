// 2025-05-25 카드 정렬하기
// 자료 구조 / 그리디 알고리즘 / 우선순위 큐
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        pq.push(k);
    }
    int ans = 0;
    int cur = pq.top();
    pq.pop();
    while(!pq.empty()){
        if(cur == -1){
            cur = pq.top();
            pq.pop();
        } else {
            int k = pq.top() + cur;
            ans += k;
            cur = -1;
            pq.pop();
            pq.push(k);
        }
    }

    cout << ans;

}