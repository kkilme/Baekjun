// 2025-04-13 가장 긴 증가하는 부분수열
// DP
#include <iostream>

using namespace std;

int num[1000];
int dp[1000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int answer = 0;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> num[i];

    for(int i = 0; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(num[j] < num[i]) {
                dp[i] = max(dp[i], dp[j]+1); 
            }
        }
        answer = max(answer, dp[i]);
    }

    cout << answer;
}