// 2024-09-11 Gum Gum for Jay Jay
// Implementation

#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    string s;
    while(!cin.eof()){
        getline(cin, s);
        if(s != "") n++;
    }

    cout << n;
}