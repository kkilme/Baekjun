// 2025-02-25 색종이 만들기
// 분할 정복 / 재귀
#include <iostream>
#include <vector>
using namespace std;

int white = 0, blue = 0;

void find(vector<vector<int>> &v, int x, int y, int size){
    if(size == 1){
        if(v[x][y] == 0) white++;
        else blue++;
        return;
    }

    int cur = v[x][y];
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(v[i][j] != cur){
                find(v, x, y, size/2);
                find(v, x + size/2, y, size/2);
                find(v, x, y + size/2, size/2);
                find(v, x + size/2, y + size/2, size/2);
                return;
            }
        }
    }
    if(cur == 0) white++;
    else blue++;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    find(v, 0, 0, n);

    cout << white << '\n' << blue;
}