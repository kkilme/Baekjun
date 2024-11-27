// 20241127 구간 합 구하기 4
// 누적 합
#include <iostream>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v;

    int k;
    v.push_back(0);

    for(int i = 1; i<=n; i++){
        cin >> k;
        v.push_back(v[i-1]+k);
    }

    while(m--){
        int i, j;
        cin >> i >> j;
        cout << v[j] - v[i-1] << '\n';
    }
}