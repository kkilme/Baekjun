// 2025-05-11 A와 B
// 구현 / 문자열 / 그리디 알고리즘
#include <iostream>
#include <string>
#include <algorithm>
#include <string_view>
using namespace std;

string s, t;
int answer = 0;
void solve(string_view cur, int sz, bool isReversed){
    if(answer) return;
    if(sz == s.size()){
        string cur2(cur);
        if(isReversed){
            reverse(cur2.begin(), cur2.end());
        }
        if(cur2 == s){
            answer = 1;
        }
        return;
    }
    if(!isReversed){
        char last = cur[cur.size()-1];
        cur.remove_suffix(1);
        if(last == 'B'){
            solve(cur, sz-1, !isReversed);
        } else {
            solve(cur, sz-1, isReversed);
        }
    } else {
        char first = cur[0];
        cur.remove_prefix(1);
        if(first == 'B'){
            solve(cur, sz-1, !isReversed);
        } else {
            solve(cur, sz-1, isReversed);
        }
    }
}

int main(){
    cin >> s >> t;
    solve(t, t.size(), false);
    
    cout << answer;
}