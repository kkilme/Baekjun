// 2025-01-09 탑
// 자료 구조 / 스택
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[500000];
int tops[500000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> tops[i];
        ans[i] = 0;
    }

    vector<int> s;
    
    for(int i = n; i>=0; i--){
        while(!s.empty() && tops[s.back()] < tops[i]){
            int k = s.back();
            s.pop_back();
            ans[k] = i;
        }
        s.push_back(i);
    }


    for(int i = 1; i<=n; i++){
        cout << ans[i] << ' ';
    }

}