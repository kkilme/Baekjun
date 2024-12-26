// 2024-12-27 N과 M (1)
// 백트래킹
#include <iostream>

using namespace std;

int n, m;
bool visit[9] = {false,};

void dfs(int curs[], int cur, int depth){
    if(depth == m){
        for(int i = 0; i<m-1; i++){
            cout << curs[i] << ' ';
        }
        cout << cur << '\n';
        return;
    }

    for(int i = 1; i<=n; i++){
        if(!visit[i]){
            visit[i] = true;
            curs[depth] = i;
            dfs(curs, i, depth+1);
            visit[i] = false;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int arr[m];

    dfs(arr, 0, 0);
}