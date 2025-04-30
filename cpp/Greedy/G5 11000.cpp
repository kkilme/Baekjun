// 2025-05-01 강의실 배정
// 그리디 / 자료 구조 / 정렬 / 우선순위 큐
#include <bits/stdc++.h>
using namespace std;

pair<int, int> classes[200001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> classes[i].first >> classes[i].second;
    }

    sort(classes, classes+n, [](pair<int, int> a, pair<int, int> b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    priority_queue<int> cur;
    cur.push(-classes[0].second);

    for(int i = 1; i<n; i++){
        int start = classes[i].first;
        int end = classes[i].second;

        if(-cur.top() <= start){
            cur.pop();
            cur.push(-end);
        } else {
            cur.push(-end);
        }
    }
    cout << cur.size();
}