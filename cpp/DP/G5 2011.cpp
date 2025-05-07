// 2025-05-07 암호코드
// DP
#include <bits/stdc++.h>
using namespace std;

string s;
int dp[5005];

int main(){

    cin >> s;
    if(s[0] == '0'){
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    int prev = s[0]-'0';
    for(int i = 2; i <= s.size(); i++){
        int c = s[i-1] - '0';
        if(c == 0){
            if(prev == 0 || prev > 2){
                cout << 0;
                return 0;
            } else {
                dp[i] = dp[i-2];
            }
            
        } else if(prev == 2 && c > 6){
            dp[i] = dp[i-1];
        } else if(prev == 0 || prev > 2){
            dp[i] = dp[i-1];
        } else {
            dp[i] = dp[i-1] + dp[i-2];
        }
        prev = c;
        dp[i] %= 1000000;
    }

    cout << dp[s.size()] << endl;
}