// 나는야 포켓몬 마스터 이다솜
// map
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    map<string, string> dogam;
    string in;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> in;
        dogam.insert({in, to_string(i+1)});
        dogam.insert({to_string(i+1), in});
    }

    for(int i = 0; i < m; i++){
        cin >> in;

        cout << dogam[in] << "\n";
    }
}