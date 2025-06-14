// 2025-06-14 이중 우선순위 큐
// 자료 구조 / 트리를 사용한 집합과 맵? / 우선순위 큐 / 집합과 맵?
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        priority_queue<int, vector<int>, greater<>> minq;
        priority_queue<int, vector<int>, greater<>> maxRemovedq;
        priority_queue<int> maxq;
        priority_queue<int> minRemovedq;
        while(k--){
            char c; int n;
            cin >> c >> n;

            if(c == 'I'){
                minq.push(n);
                maxq.push(n);
            } else {
                if(n == -1){
                    while(!maxRemovedq.empty() && !minq.empty() && minq.top() == maxRemovedq.top()){
                        minq.pop();
                        maxRemovedq.pop();
                    }
                    if(!minq.empty()){
                        int a = minq.top();
                        minq.pop();
                        minRemovedq.push(a);
                    }
                } else if(n == 1){
                    while(!minRemovedq.empty() && !maxq.empty() && maxq.top() == minRemovedq.top()){
                        maxq.pop();
                        minRemovedq.pop();
                    }
                    if(!maxq.empty()){
                        int a = maxq.top();
                        maxq.pop();
                        maxRemovedq.push(a);
                    }
                }
            }
        }
        while(!maxRemovedq.empty() && !minq.empty() && minq.top() == maxRemovedq.top()){
            minq.pop();
            maxRemovedq.pop();
        }
        while(!minRemovedq.empty() && !maxq.empty() && maxq.top() == minRemovedq.top()){
            maxq.pop();
            minRemovedq.pop();
        }
        if(maxq.empty()) cout << "EMPTY\n";
        else{
            cout << maxq.top() << ' ';
            cout << minq.top() << '\n';            
        }

    }

}