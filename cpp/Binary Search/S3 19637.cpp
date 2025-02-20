// 2025-02-21 IF문 좀 대신 써줘
// 이분탐색
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<pair<string, int>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 0; i<m; i++){
        int k;
        cin >> k;

        int l = 0, r = n-1;

        while(l<r){
            int mid = (l+r)/2;
            if(v[mid].second < k){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        cout << v[l].first << '\n';
    }

}