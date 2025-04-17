// 2025-04-18 IOIOI
// 스트링
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    string s;

    cin >> n >> m >> s;

    char prv = ' ';
    int k;
    int answer = 0;

    for(int i = 0; i<m; i++){
        char cur = s[i];
        if(cur == 'I'){
            if(prv == 'O' && k != 0){
                k++;
            } else k = 1;
            if(k >= 2*n + 1) answer++;

        } else {
            if(prv == 'I'){
                k++;
            } else k = 0;
        }
        prv = cur;
    }

    cout << answer;

}