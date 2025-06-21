// 2025-06-22 행렬 제곱
// 수학 / 분할 정복 / 분할 정복을 이용한 거듭제곱 / 선형 대수학
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int memo[40][5][5];

int main(){

    ll n, b;
    cin >> n >> b;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> memo[0][i][j];
        }
    }
    for(int i = 1; i<40; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                for(int l = 0; l<n; l++){
                    memo[i][j][k] += memo[i-1][j][l] * memo[i-1][l][k];
                    memo[i][j][k] %= 1000;
                }
            }
        }
    }

    int ans[5][5];
    int temp[5][5];
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(i == j) ans[i][j] = 1;
            else ans[i][j] = 0;
        }
    }
    int i = 39;
    while(b > 0 && i>=0){
        ll cur = pow(2, i);
        if(cur > b) {i--; continue;}
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                int sum = 0;
                for(int l = 0; l<n; l++){
                    sum += ans[j][l] * memo[i][l][k];
                    sum %= 1000;
                }
                temp[j][k] = sum;
            }
        }
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                ans[j][k] = temp[j][k];
            }
        }
        b -= cur;
        
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

}