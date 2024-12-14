// 2024-09-09 Periods
// String

#include <iostream>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    string s;
    cin.ignore();
    while(t--){
        getline(cin, s);
        if(s[s.length()-1] != '.'){
            s.append(".");
        }
        cout << s << '\n';
    }
}
