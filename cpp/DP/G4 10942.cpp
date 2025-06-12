// 2025-06-12 팰린드롬?
// DP
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2000];
int dp[2000][2000];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i<n; i++){
        int l,r;
        l = i-1;
        r = i+1;
        dp[i][i] = 1;
        while(l >= 0 && r < n){
            dp[l--][r++] = dp[l+1][r-1] && arr[l] == arr[r];
        }
        l = i;
        r = i+1;
        dp[l--][r++] = arr[l] == arr[r];
        while(l >= 0 && r < n){
            dp[l--][r++] = dp[l+1][r-1] && arr[l] == arr[r];
        }        
    }

    int m;
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << dp[l-1][r-1] << '\n';
    }

}