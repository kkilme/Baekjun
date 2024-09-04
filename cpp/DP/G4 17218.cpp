// 비밀번호 만들기
// DP - Longest Common Subsequence

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string a, b, answer="";

    cin >> a >> b;

    int n = a.length(), m = b.length();
    int lcs[41][41];
    memset(lcs, 0, sizeof(lcs));
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } else{
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    // for(int i = 0; i<=n; i++){
    //     for(int j = 0; j<=m; j++){
    //         cout << lcs[i][j];
    //     }
    //     cout << endl;
    // }
    while (true)
    {   
        if(n == 0 || m == 0) break;
        if(lcs[n][m] == lcs[n-1][m]){
            n--;
        } else if(lcs[n][m] == lcs[n][m-1]){
            m--;
        } else {
            answer.insert(0, string(1, a[n-1]));
            n--; m--;
        }
    }
    cout << answer;
}