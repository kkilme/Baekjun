// 2025-01-02 A와 B 2
// 문자열 / 브루트포스 / 재귀
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> found;
string s, t;

void tryfind(string st, int len){

    if(len<s.size()) return;
    found.push_back(st);
    string st2 = st;
    if(st[st.size()-1] == 'A'){
        st2.pop_back();
        tryfind(st2, len-1);
    }
    if(st[0] == 'B'){
        reverse(st.begin(), st.end());
        st.pop_back();
        tryfind(st, len-1);
    }
}

int main(){

    cin >> s >> t;

    tryfind(t, t.size());

    auto it = find(found.begin(), found.end(), s);
    if(it == found.end()) cout << 0;
    else cout << 1;
}