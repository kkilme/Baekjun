// 2025-03-02 수 이어 쓰기
// 구현 / 그리디 알고리즘 / 문자열 / 브루트포스 알고리즘
#include <iostream>
#include <string>
using namespace std;

string n;
int cur = 1;

int check(int idx){
    string c = to_string(cur);
    
    int next = 0;
    int match = 0;
    for(int i = 0; i<c.size(); i++){
        if(n[idx + next] == c[i]){
            match++;
            next++;
        }
    }
    return match;
}

int main(){

    cin >> n;

    int idx = 0;
    while(idx < n.size()){
        int k = 0;
        while(!k){
            k = check(idx);
            cur++;
        }
        idx += k;
    }

    cout << cur-1;
}