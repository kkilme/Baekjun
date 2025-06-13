// 2025-06-14 단어 수학
// 그리디 알고리즘
// 내 머리론 떠올리지 못했을 풀이
#include <bits/stdc++.h>
using namespace std;

long long arrs[26];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> v;
    string s;
    while(cin >> s) v.push_back(s);

    for(string s: v){
        int k = 1;
        for(int i = s.size() - 1; i>=0; i--){
            arrs['Z'-s[i]] += k;
            k *= 10;
        }
    }
    
    long long answer = 0;
    vector<long long> weights;
    for(int i = 0; i<26; i++){
        if(arrs[i] != 0) weights.push_back(arrs[i]);
    }

    sort(weights.begin(), weights.end(), greater<>());
    int k = 9;
    for(auto w: weights){
        answer += k * w;
        k--;
    }

    cout << answer;
}