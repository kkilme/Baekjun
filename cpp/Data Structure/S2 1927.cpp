// 2025-02-25 최소 힙
// 자료 구조 / 우선순위 큐
#include <iostream>
#include <queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> pq;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if(k) pq.push(-k);
        else {
            if(pq.empty()) cout << 0;
            else {
                cout << -pq.top();
                pq.pop();
            }
            cout << '\n';
        }
    }    
}