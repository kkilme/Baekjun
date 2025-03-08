// 2025-03-08 가희와 키워드
// 자료구조 / 문자열 / 해시를 사용한 집합과 맵 / 파싱
#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> mp;

    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        mp.insert({s, 1});
    }

    for(int i = 0; i<m; i++){
        string s;
        cin >> s;
        string cur = "";
        for(char c: s){
            if(c != ',') cur += c;
            else{
                mp.erase(cur);
                cur = "";
            }
        }
        mp.erase(cur);
        cout << mp.size() << '\n';
    }
}