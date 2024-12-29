// 2024-12-30 1, 2, 3 더하기 4
// DP
#include <iostream>

using namespace std;

int memo[10001][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memo[1][1] = 1;
    memo[2][1] = 1;
    memo[2][2] = 1;
    memo[3][1] = 1;
    memo[3][2] = 1;
    memo[3][3] = 1;

    for(int i = 4; i<=10001; i++){
        memo[i][1] = memo[i-1][1];
        memo[i][2] = memo[i-2][1] + memo[i-2][2];
        memo[i][3] = memo[i-3][1] + memo[i-3][2] + memo[i-3][3];
    }
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << memo[n][1] + memo[n][2] + memo[n][3] << '\n';
    }
}

// 1 1 1
// 1 2
// 3

// 1 1 1 1
// 1 1 2
// 2 2
// 1 3

// 1 1 1 1 1
// 1 1 1 2
// 1 2 2
// 1 1 3
// 2 3
