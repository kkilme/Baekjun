// 2025-02-09 성냥개비
// DP / 그리디?
#include <iostream>
#include <string>
using namespace std;

string dp[101];
string dp2[101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[2] = "1"; dp[3] = "7"; dp[4] = "4"; dp[5] = "2"; dp[6] = "6"; dp[7] = "8"; dp[8] = "10";
    dp[9] = "18"; dp[10] = "22"; dp[11] = "20"; dp[12] = "28"; dp[13] = "68"; dp[14] = "88"; dp[15] = "108";
    dp[16] = "188"; dp[17] = "200";

    dp2[2] = "1"; dp2[3] ="7";

    for(int i = 4; i<=100; i++){
        dp2[i] = dp2[i-2] + "1";
    }

    for(int i = 18; i<=100; i++){
        dp[i] = dp[i-7] + "8";
    }
    int t;
    cin >> t;
    for(int i = 0; i<t; i++){
        int n;
        cin >> n;    
        cout << dp[n] << ' ' << dp2[n] << '\n';
    }
}
// 2 3 4  5  6  7  8  9  10
// 1 7 11 71 111 711 1111 7111 11111
/*
n 2 3 4 5 6 7 8 9 10
smallest 1 7 4 2 6 8 10 18 23

n%7      4   5   6   0   1  2   3
n 11 12 13 14 15 16   17
smallest 20 28 68 88 108 188  200

n%7   4     5    6     0    1     2     3
n   18    19   20   21   22   23   24

smallest 208  288 688 888 1088 1888 2008
*/