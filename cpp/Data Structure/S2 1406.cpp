// 2024-12-16 에디터
// 연결 리스트 / 스택? / 자료 구조
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string st;
    list<char> s;
    char comm, c;

    cin >> st;
    for(char c: st){
        s.push_back(c);
    }

    int m;
    cin >> m;

    auto idx = s.end();
    while(m--){
        cin >> comm;
        if(comm == 'P'){
            cin >> c;
            idx = s.insert(idx, c);
            idx++;
        } else if (comm == 'L' && idx != s.begin()){
            idx--;
        } else if (comm == 'D' && idx != s.end()){
            idx++;
        } else if (comm == 'B'){
            if(idx != s.begin()) idx = s.erase(--idx);
        }
    }
    for(char c: s){
        cout << c;
    }
}