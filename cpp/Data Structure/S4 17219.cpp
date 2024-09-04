// 2024-09-05 비밀번호 찾기
// hashmap
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    map<string, string> memo;
    string name, pass;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> name >> pass;
        memo.insert({name, pass});
    }

    for(int i = 0; i < m; i++){
        cin >> name;
        cout << memo[name] << "\n";
    }
}