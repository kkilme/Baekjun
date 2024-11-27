// 20241126 패션왕 신해빈
// 수학 / 자료구조
// 조합론 / 해시를 사용한 집합과 맵
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        map<string, int> clothes;

        while(n--){
            string a, b;
            cin >> a >> b;
            clothes[b]++;
        }
        int answer = 1;
        for(auto it = clothes.begin(); it!=clothes.end(); it++){
            answer *= it->second + 1;
        }
        cout << answer - 1 << endl;
    }
}