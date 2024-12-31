// 2025-01-01 집 주소
// 수학
#include <iostream>
#include <string>
using namespace std;

int main(){

    while(true){
        string s;
        cin >> s;
        if(s == "0") break;
        int answer = 1;
        for(char c:s){
            if(c == '0') answer += 4;
            else if (c == '1') answer += 2;
            else answer += 3;
            answer++;
        }
        cout << answer << '\n';
    }
}