// 2025-01-25 문자열 폭발
// 자료구조 / 문자열 / 스택
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string s, bomb;

    cin >> s >> bomb;

    vector<char> st;

    for(int i = 0; i<s.size(); i++){
        st.push_back(s[i]);
        if(st.size() >= bomb.size() && st.back() == bomb[bomb.size()-1]){
            while(true){
                bool brk = false;
                for(int j = 0; j<bomb.size(); j++){
                    if(st.size() == 0 || st[st.size()-1-j] != bomb[bomb.size()-1-j]) {
                        brk = true;
                        break;
                    }
                }
                if(brk) break;

                for(int j = 0; j<bomb.size(); j++){
                    st.pop_back();
                }
            }
        }
    }
    if(st.size() == 0) cout << "FRULA";
    else{
        for(int i = 0; i<st.size(); i++){
            cout << st[i];
        }
    }
}