// 2024-12-28 N과 M (4)
// 백트래킹
#include <iostream>

using namespace std;

int n, m;

void dfs(int curs[], int cur, int depth){
    if(depth == m){
        for(int i = 0; i<m-1; i++){
            cout << curs[i] << ' ';
        }
        cout << cur << '\n';
        return;
    }

    for(int i = cur; i<=n; i++){
        curs[depth] = i;
        dfs(curs, i, depth+1);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int arr[m];

    dfs(arr, 1, 0);
}