// 2025-05-20 테트로미노
// 구현 / 브루트포스
#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
int visited[501][501];
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int sum;
int answer;
int n, m;

void bt(int x, int y, int depth){
    if(depth == 4){
        answer = max(answer, sum);
        return;
    }
    for(int i = 0; i<4; i++){
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx]){
            visited[ny][nx] = true;
            sum += arr[ny][nx];
            bt(nx, ny, depth+1);
            if(depth == 2) bt(x, y, depth+1);
            visited[ny][nx] = false;
            sum -= arr[ny][nx];
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            visited[i][j] = true;
            sum += arr[i][j];
            bt(j, i, 1);
            visited[i][j] = false;
            sum -= arr[i][j];
        }
    }
    cout << answer;
}