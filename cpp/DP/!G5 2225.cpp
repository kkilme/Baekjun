// 2025-04-08 합분해
// 수학 / DP
// 중복 조합과 동일 nHk = n+k-1Ck-1
#include <iostream>

using namespace std;

int dp[201][201];
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i<=n; i++){
        dp[i][1] = 1;
    }
    for(int i = 0; i<=k; i++){
        dp[0][i] = 1;
    }
    for(int i = 2; i<=k; i++){
        for(int j = 1; j<=n; j++){
            dp[j][i] = (dp[j][i-1] + dp[j-1][i]) % 1000000000;
        }
    }

    cout << dp[n][k];
}

/*
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.
덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.
*/