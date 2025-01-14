// 2025-01-15 임스와 함께하는 미니게임
// 자료 구조 / 문자열? / 해시를 사용한 집합과 맵
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    char c;

    cin >> n >> c;

    int num;
    if(c == 'Y') num = 1;
    else if(c == 'F') num = 2;
    else num = 3;

    int answer = 0;
    int cur = 0;
    string s;
    unordered_set<string> ss;
    for(int i = 0; i<n; i++){
        cin >> s;
        if(ss.find(s) == ss.end()){
            ss.insert(s);
            cur++;
            if(cur == num){
                answer++;
                cur = 0;
            }
        }
    }

    cout << answer;
}