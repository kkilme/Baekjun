// 2024-09-10 얼룩말을 찾아라!
// string

#include <iostream>
#include <map>

using namespace std;

int main(){

    int n, l, sum=0;
    map<int, int> m;

    cin >> n >> l;

    string s;
    char before;
    while(n--){
        sum = 0; before = '0';
        cin >> s;
        for(int i = 0; i<l; i++){
            if(before == '0' && s[i] == '1'){
                sum++;
            }
            before = s[i];
        }
        m[sum]++;
    }

    auto it = m.rbegin();

    cout << it->first << ' ' << it->second;

}
