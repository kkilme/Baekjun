// 2024-12-17 단어 뒤집기 2
// 구현 / 문자열 / 자료 구조? / 스택?
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cur = "";
bool inB = false;

void printreverse(bool addspace){
    if(cur.empty()) return;
    reverse(cur.begin(), cur.end());
    cout << cur;
    if(addspace) cout << ' ';
    cur = "";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);

    for(int i=0; i<s.length(); i++){
        char c = s[i];

        if(c == '<'){
            inB = true;
            printreverse(false);
        }

        if(!inB && c == ' '){
            printreverse(true);
            continue;
        }

        cur += c;

        if(c == '>'){
            cout << cur;
            cur = "";
            inB = false;
        }
    }
    printreverse(false);
}