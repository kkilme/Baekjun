// 2025-03-22 회의실 배정
// 그리디 알고리즘 / 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(b, a);
    }
    sort(v.begin(), v.end());
    int cur = 0;
    int answer = 0;
    for(int i = 0; i<n; i++){
        int a = v[i].first, b = v[i].second;
        if(cur <= b){
            cur = a;
            answer++;
        }
    }
    cout << answer;
}