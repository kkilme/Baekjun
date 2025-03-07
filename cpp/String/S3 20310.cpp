// 2025-03-08 타노스
// 문자열 / 그리디 알고리즘?
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int zero = 0;
    int one = 0;

    for(char c: s){
        if(c == '0') zero++;
        else one++;
    }
    int ss = s.size();

    int cur = 0;

    for(int i = 0; i<ss && cur < one / 2; i++){
        auto it = s.find('1');
        s.erase(it, 1);
        cur++;
    }
    cur = 0;
    ss = s.size();
    reverse(s.begin(), s.end());
    for(int i = 0; i<ss && cur < zero / 2; i++){
        auto it = s.find('0');
        s.erase(it, 1);
        cur++;
    }
    reverse(s.begin(), s.end());
    cout << s;
}