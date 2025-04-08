// 2025-04-09 전깃줄
// DP - LIS 구하기
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[100];
int dp[100];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);

    for(int i = 0; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[j].second < arr[i].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << n - *max_element(dp, dp + n) << "\n";
}