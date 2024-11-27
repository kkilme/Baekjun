// 20241127 구간 합 구하기 5
// 누적 합 / 다이나믹 프로그래밍
#include <iostream>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(1025, vector<int>(1025, 0));

    int k;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> k;
            int a = 0, b = 0;
            a = arr[i-1][j];
            b = arr[i][j-1];
            arr[i][j] = a + b + k - arr[i-1][j-1];
        }
    }

    while(m--){
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << arr[i2][j2] - arr[i1-1][j2] - arr[i2][j1-1] + arr[i1-1][j1-1]<< '\n';
    }
}