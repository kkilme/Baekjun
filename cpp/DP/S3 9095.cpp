// 1, 2, 3 더하기
// DP

#include <iostream>

using namespace std;

int main(){

    int T, n;
    int memo[11];
    memo[0] = 1; memo[1] = 2; memo[2] = 4;
    for(int i = 3; i<11; i++){
        memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
    }
    cin >> T;

    while(T--){
        cin >> n;
        cout << memo[n-1] << endl;
    }
}