// 2024-10-30 집합
// 구현, 비트마스킹

#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;

    cin >> m;

    bool S[20] = {0,}; 

    string cmd;
    int n;

    while(m--){
        cin >> cmd;
        if(cmd == "all") {
            for(int i = 0; i<20; i++){
                S[i] = 1;
            }
        }
        else if(cmd == "empty"){
            for(int i = 0; i<20; i++){
                S[i] = 0;
            }
        }
        else{
            cin >> n;
            if(cmd == "add") S[n-1] = 1;
            else if (cmd == "remove") S[n-1] = 0;
            else if (cmd == "check") cout << S[n-1] << '\n';
            else if (cmd == "toggle") S[n-1] = !S[n-1];
        }
    }
}