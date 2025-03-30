// 2025-03-30 암호 만들기
// 수학 / 브루트포스 / 조합론 / 백트래킹
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
char alphabets[15];

void backtrack(int idx, int depth, int use[]){
    if(depth == l){
        int mos = 0, jas = 0;
        string s = "";
        for(int i = 0; i<c; i++){
            if(use[i] == 1){
                s += alphabets[i];
                if(alphabets[i] == 'a' || alphabets[i] == 'e' || alphabets[i] == 'i' || alphabets[i] == 'o' || alphabets[i] == 'u'){
                    mos++;
                }else{
                    jas++;
                }
            }
        }
        if(mos >= 1 && jas >= 2){
            cout << s << '\n';
        }
        return;
    }
    for(int i = idx; i < c; i++){
        if(use[i] == 1) continue;
        use[i] = 1;
        backtrack(i+1, depth+1, use);
        use[i] = 0;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> c;
    for(int i = 0; i<c; i++){
        cin >> alphabets[i];
    }
    sort(alphabets, alphabets + c);
    int use[15] = {0,};
    backtrack(0, 0, use);
}