// 2025-07-07 ROT13
// 구현 / 문자열
#include <bits/stdc++.h>
using namespace std;

vector<char> vowel = {'a', 'i', 'y', 'e', 'o', 'u'};
vector<char> consonant = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};

int findindex(vector<char>& v, char c){
    for(int i = 0; i<v.size(); i++){
        if(v[i] == c) return i;
    }
    return -1;
}

int main(){

    string s;
    while(!cin.eof()){
        getline(cin, s);
        string ans = "";
        for(char c: s){
            if('a' <= c && c <= 'z'){
                int i = findindex(vowel, c);
                if(i != -1){
                    ans.push_back(vowel[(i - 3 + 6) % 6]);
                } else {
                    i = findindex(consonant, c);
                    ans.push_back(consonant[(i - 10 + 20) % 20]);
                }
            } else if ('A' <= c && c <= 'Z'){
                int i = findindex(vowel, tolower(c));
                if(i != -1){
                    ans.push_back(toupper(vowel[(i - 3 + 6) % 6]));
                } else {
                    i = findindex(consonant, tolower(c));
                    ans.push_back(toupper(consonant[(i - 10 + 20) % 20]));
                }
            } else {
                ans.push_back(c);
            }
        }
        cout << ans << '\n';
    }
}