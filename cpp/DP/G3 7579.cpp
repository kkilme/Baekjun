// 2025-07-16 앱
// DP / 배낭 문제
#include <bits/stdc++.h>
using namespace std;

int dp[10001];
pair<int, int> arr[100];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cin >> arr[i].first;
    }

    for(int i = 0; i<n; i++){
        cin >> arr[i].second;
    }

    for(int i = 0; i<n; i++){
        for(int j = 10000; j>=arr[i].second; j--){
            dp[j] = max(dp[j], dp[j-arr[i].second] + arr[i].first);
        }
        
    }

    for(int i = 0; i<10001; i++){
        if(dp[i] >= m){
            cout << i;
            break;
        }
    }
}