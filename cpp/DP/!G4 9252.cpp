// 2025-06-08 LCS 2
// DP / 문자열 / 역추적 / LCS문제
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int path[1001][1001];

int main(){

    string s, t;
    cin >> s >> t;

    for(int i = 1; i<=s.length(); i++){
        for(int j = 1; j <= t.length(); j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                path[i][j] = 3;
            } else {
                if(dp[i][j-1] < dp[i-1][j]){
                    path[i][j] = 1;
                } else path[i][j] = 2;
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int i, j;
    i = s.length(); j = t.length();
    cout << dp[i][j] << '\n';
    string ans;
    while(dp[i][j] != 0){
        if(path[i][j] == 3){
            ans.push_back(s[i-1]);
            i--; j--;
        } else if(path[i][j] == 2){
            j--;
        } else i--;
    }
    reverse(ans.begin(), ans.end());
    for(char c: ans){
        cout << c;
    }

}