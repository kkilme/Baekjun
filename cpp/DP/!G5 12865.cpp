// 2025-03-24 평범한 배낭
// DP / 배낭 문제
#include <iostream>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K;
    cin >> n >> K;

    vector<int> dp(K+1, 0);
    // dp[j]: 무게 제한이 j일 때 얻을 수 있는 최대 가치
    for(int i = 0; i<n; i++){
        int w, v;
        cin >> w >> v;
        for(int j = K; j>=w; j--){ // 내림차순으로 순회해야 중복 사용을 방지할 수 있음
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }

    cout << dp[K];
}

/* 2차원 배열 풀이
dp[i][j]는:
i: 앞에서부터 i번째 물건까지 고려
j: 현재 배낭의 무게 한도가 j일 때
해당 상태에서 얻을 수 있는 최대 가치
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> weights(N + 1);
    vector<int> values(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            // 물건을 넣지 않는 경우
            dp[i][j] = dp[i-1][j];

            // 물건을 넣을 수 있는 경우 (현재 무게 j가 weights[i] 이상인 경우)
            if (j >= weights[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - weights[i]] + values[i]);
            }
        }
    }

    // 최종 결과: dp[N][W]가 최대 가치
    cout << dp[N][W] << "\n";
    return 0;
}
*/