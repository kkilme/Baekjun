// 2025-01-06 문자열 게임 2
// 문자열 / 슬라이딩 윈도우? / (투 포인터)
#include <iostream>
#include <string>
using namespace std;

string s;
int k;
int shorte, longe;

void findsl(char c){
    int l = 0; int r = 0;
    int curc = s[0] == c;
    int curlength = 1;
    while(l < s.length()){
        if (curc < k && r < s.length()){
            if(s[++r] == c) curc++;
            curlength++;
        } else {
            if(curc == k) shorte = min(shorte, curlength);
            if(curc == k && s[r] == c && s[l] == c) longe = max(longe, curlength);
            if(s[l++] == c) curc--;
            curlength--;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        cin >> s >> k;

        shorte = 99999;
        longe = -1;
        for(char c = 'a'; c <='z'; c++){
            if(s.find(c) == string::npos) continue;
            findsl(c);
        }
        if(shorte == 99999 || longe == -1) cout << -1 << '\n';
        else cout << shorte << ' ' << longe << '\n';
    }
}