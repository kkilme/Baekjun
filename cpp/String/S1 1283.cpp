// 2025-03-22 단축키 지정
// 구현 / 문자열
#include <iostream>
#include <string>
using namespace std;

int main(){

    int n;
    cin >> n;
    bool used[26] = {0,};
    cin.ignore();
    for(int i = 0; i<n; i++){
        string s;
        getline(cin, s);
        char prev = ' ';
        bool flag = false;
        for(int j = 0; j<s.size() && !flag; j++){
            if(prev == ' '){
                char c = toupper(s[j]);
                if(!used[c - 'A']){
                    used[c - 'A'] = true;
                    s.insert(j, "[");
                    s.insert(j+2, "]");
                    cout << s << '\n';
                    
                    flag = true;
                }
            }
            prev = s[j];
        }
        if(flag) continue;
        for(int j = 0; j<s.size(); j++){
            if(s[j] == ' ') continue;
            char c = toupper(s[j]);
            if(!used[c - 'A']){
                used[c - 'A'] = true;
                s.insert(j, "[");
                s.insert(j+2, "]");
                cout << s << '\n';
                flag = true;
                break;
            }
        }
        if(!flag) cout << s << '\n';
    }
}