// 2024-12-19 쇠막대기
// 자료구조? / 스택?
#include <iostream>
#include <string>
using namespace std;

int main(){

    string s;
    cin >> s;

    char before = ')';
    int cur = 0, answer = 0;
    for(int i = 0; i<s.size(); i++){
        char c = s[i];

        if(c == '('){
            if(before == '('){
                cur++;
            }
            before = '(';
        } else if(c == ')'){
            if(before == '('){
                answer += cur;
            } else {
                answer += 1;
                cur--;
            }
            before = ')';
        }
    }
    cout << answer;
}