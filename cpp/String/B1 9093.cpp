// 2024-12-14 단어 뒤집기
// 문자열, 구현

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;
    cin.ignore();

    while(t--){
        string s;
        getline(cin, s);

        string cur = "";

        for(int i = 0; i<s.length(); i++){
            if(s[i] == ' '){
                reverse(cur.begin(), cur.end());
                cout << cur << ' ';
                cur = "";
            }
            else{
                cur.insert(cur.end(), s[i]);
            }
        }
        reverse(cur.begin(), cur.end());
        cout << cur << '\n';
    }
}