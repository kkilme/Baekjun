// 2025-03-20 문자열 교환
// 브루트포스? / 슬라이딩 윈도우
// no idea
#include <iostream>
#include <string>
using namespace std;

int main(){

    string s;
    cin >> s;
    int cnt = 0;
    for(char c : s){
        if(c == 'a') cnt++;
    }
    s += s;
    int as = 0;
    for(int i = 0; i<cnt; i++){
        if(s[i] == 'a') as++;
    }
    // 전체 a 개수가 cnt개면 cnt크기의 sliding window에 a가 다 들어와야 함
    // 그러므로 전체 a 개수에서 sliding window에 들어있는 a 개수를 빼면 교환 횟수가 나옴
    int ans = cnt - as;
    int l = 0, r = cnt-1;
    while (r<s.size())
    {
        if(s[++r] == 'a') as++;
        if(s[l++] == 'a') as--;
        ans = min(ans, cnt-as);
    }
    cout << ans;
}