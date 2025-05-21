// 2025-05-22 동전 1
// DP
// 3067, 9804와 동일?
#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int coins[100];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i<n; i++){
        cin >> coins[i];
    }

    sort(coins, coins+n);

    dp[0] = 1;

    for(int i = 0; i<n; i++){
        for(int j = coins[i]; j<=k; j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    cout << dp[k];    
}

/*
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다.
사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.
*/