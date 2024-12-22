// 2024-12-22 수 고르기
// 투 포인터
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
       
    cin >> n >> m;
    vector<int> v(n);
    
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int cur = 0, answer = 2000000001;
    if(m == 0) answer = 0;
    int i = 0, j = 0;

    while(i != n-1){
        if(cur < m && j != n-1){
            cur = v[++j] - v[i];
        } else {
            cur = v[j] - v[++i];
        }

        if(cur >= m) answer = min(answer, cur);
    }
    cout << answer;
}