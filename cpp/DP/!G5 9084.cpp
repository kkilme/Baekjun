// 2025-05-09 동전
// DP / 배낭 문제
// 3067과 동일
#include <bits/stdc++.h>
using namespace std;

int coins[20];
int dp[10001][20];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> coins[i];
        }
        int m;
        cin >> m;

        fill(dp[0], dp[0] + 10001 * 20, 0);

        for(int i = 0; i<n; i++){
            dp[coins[i]][i] = 1;
        }

        for(int i = coins[0]+1; i<=m; i++){
            for(int j = 0; j<n; j++){
                if(i - coins[j] < 0) continue;
                for(int k = 0; k<=j; k++){      
                    dp[i][j] += dp[i-coins[j]][k];
                }   
            }

        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            ans += dp[m][i];
        }
        cout << ans << '\n';
    }
}

/* 더 좋은 풀이
int N;
cin >> N;
vector<int> coin(N);
for(int i = 0; i < N; i++){
    cin >> coin[i];
}
int M;
cin >> M;

// dp[j] = 금액 j 를 만드는 방법의 수
vector<ll> dp(M+1, 0);
dp[0] = 1;

// 동전 종류별로 DP 갱신
// 동전이 정렬되어있지 않아도 상관없음
for(int c : coin){
    for(int j = c; j <= M; j++){
        dp[j] += dp[j - c];
    }
}

cout << dp[M] << "\n";
*/