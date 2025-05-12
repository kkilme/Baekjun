// 2025-05-12 선 긋기
// 정렬 / 스위핑?
#include <bits/stdc++.h>
using namespace std;

pair<int, int> ps[1000000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> ps[i].first >> ps[i].second;
    }

    sort(ps, ps+n);

    int answer = 0;
    int l = ps[0].first;
    int r = ps[0].second;

    int curl, curr;
    for(int i = 1; i<n; i++){
        curl = ps[i].first;
        curr = ps[i].second;

        if(curl >= r){
            answer += r-l;
            l = curl;
            r = curr;
        } else if(curr > r){
            r = curr;
        }
    }
    answer += r-l;
    cout << answer;
}