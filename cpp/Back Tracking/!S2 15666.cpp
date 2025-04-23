// 2025-04-24 N과 M (12)
// 백트래킹
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
int ans[8];

void backtrack(int cur, int depth){
    if(depth == m){
        for(int i = 0; i < m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int used = -1;
    for(int i = 0; i<n; i++){
        if(used != arr[i] && arr[i] >= cur){ // 같은 depth에서 같은 수를 고르면 중복된 수열이 생성됨
            used = arr[i];
            ans[depth] = arr[i];
            backtrack(arr[i], depth + 1);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    backtrack(-1, 0);
}

/*
N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
중복되는 수열을 여러 번 출력하면 안된다.
*/