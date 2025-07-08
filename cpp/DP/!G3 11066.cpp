// 2025-07-08 파일 합치기
// DP
// 행렬 곱셈 순서 문제와 비슷 (11049)
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        vector<int> sm(k+1, 0);
        vector<vector<int>> dp(k, vector<int>(k, 0));
        for(int i = 0; i<k; i++){
            int a;
            cin >> a;
            sm[i+1] = a + sm[i]; // 구간 합을 구해놓고
        }

        for(int i = 1; i<k; i++){
            for(int j = 0; j<k-i; j++){
                int r = j + i;
                int mn = INT32_MAX;
                int idx;
                for(int l = j; l<r; l++){
                    if(mn > dp[j][l] + dp[l+1][r]){
                        mn = dp[j][l] + dp[l+1][r];
                        idx = l;
                    }
                }
                dp[j][r] = mn + sm[r+1] - sm[j]; // dp에 사용해야함
            }
        }

        cout << dp[0][k-1] << '\n';
    }
}