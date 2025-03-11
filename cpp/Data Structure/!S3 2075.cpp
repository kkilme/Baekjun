// 2025-03-12 N번째 큰 수
// 자료구조 / 정렬 / 우선순위 큐
// 공간복잡도 O(n)의 아이디어를 몬떠올림
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> heap; // minheap

    int k;
    for(int i = 0; i<n*n; i++){
        cin >> k;
        if(heap.size() < n){
            heap.push(k);
        } else if(heap.top() < k){
            heap.pop();
            heap.push(k);
        }
    }

    cout << heap.top();
}