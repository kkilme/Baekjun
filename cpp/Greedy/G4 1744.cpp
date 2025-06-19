// 2025-06-19 수 묶기
// 그리디 알고리즘 / 정렬 / 많은 조건 분기
#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return abs(a) > abs(b);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;
    int k;
    while(cin >> k) v.push_back(k);
    sort(v.begin(),v.end(),comp);

    int answer = 0;
    int neg = 0;
    int pos = 0;
    bool nozero = true;
    for(int p: v){
        if(p > 0){
            if(pos != 0){
                if(pos == 1|| p ==1) answer += pos + p;
                else answer += pos*p;
                pos = 0;
            } else {
                pos = p;
            }
        } else if (p < 0){
            if(neg != 0){
                answer += neg*p;
                neg = 0;
            } else {
                neg = p;
            }
        } else if (p == 0) nozero = false;
    }
    cout << answer + neg * nozero + pos;
}