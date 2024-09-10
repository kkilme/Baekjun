// 2024-09-10 박사 과정
// String

#include <iostream>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b;
    cin >> t;

    string s;

    while(t--){
        cin >> s;

        if(s == "P=NP"){
            cout << "skipped" << '\n';
            continue;
        }

        size_t idx = s.find("+");

        cout << stoi(s.substr(0, idx)) + stoi(s.substr(idx+1)) << '\n';
    }
}
