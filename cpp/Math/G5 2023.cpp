// 2025-05-04 신기한 소수
// 수학 / 정수론 / 백트래킹? / 소수 판정
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[6] = {1, 2, 3, 5, 7, 9};

bool isP(int x){
    if(x == 1) return false;
    int limit = sqrt(x);
    for(int i = 2; i <= limit; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void solve(int cur, int depth){
    if(depth == n){
        cout << cur << '\n';
        return;
    }
    for(int i = 0; i < 6; i++){
        int next = cur * 10 + arr[i];
        if(isP(next)){
            solve(next, depth + 1);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    solve(0, 0);
}