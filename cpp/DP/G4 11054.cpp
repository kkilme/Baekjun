// 2025-05-23 가장 긴 바이토닉 부분 수열
// DP
#include <bits/stdc++.h>
using namespace std;

int arr[1000];
int dp1[1000];
int dp2[1000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
        dp1[i] = 1;
        dp2[i] = 1;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j]){
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>i; j--){
            if(arr[i] > arr[j]){
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    cout << ans;
}