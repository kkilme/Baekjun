// 2024-12-28 N과 M (5)
// 백트래킹
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int ns[8];
int visit[8];

void dfs(int curs[], int cur, int depth){
    if(depth == m){
        for(int i = 0; i<m-1; i++){
            cout << curs[i] << ' ';
        }
        cout << cur << '\n';
        return;
    }

    for(int i = 0; i<n; i++){
        if(!visit[i]){
            visit[i] = true;
            curs[depth] = ns[i];
            dfs(curs, ns[i], depth+1);
            visit[i] = false;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cin >> ns[i];
    }
    sort(ns, ns + n);
    int arr[m];

    dfs(arr, 1, 0);
}