// 2025-02-06 디지털 티비
// 구현 / 해 구성하기
#include <iostream>
#include <string>
using namespace std;

int main(){

    int n;
    cin >> n;

    string ss[100];
    for(int i = 0; i<n; i++){
        cin >> ss[i];
    }
    string s = "";

    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(ss[i] == "KBS1") break;
        else{
            s += '1';
            cnt++;
        }
    }
    for(int i = 0; i<cnt; i++) s+='4';
    int cnt2 = 0;

    for(int i = 0; i<n; i++){
        if(ss[i] == "KBS2") break;
        else{
            s += '1';
            cnt2++;
        }
    }
    if(cnt > cnt2){
        s+= '1';
        cnt2++;
    }
    for(int i = 0; i<cnt2-1; i++) s+='4';
    cout << s;
}