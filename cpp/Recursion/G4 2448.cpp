// 2025-06-15 별 찍기 - 11
// 재귀
#include <bits/stdc++.h>
using namespace std;

int n;
string answer[3*1024];

void fill(int k, int x, int y){
    if(k == 3){
        for(int i = 0; i<5; i++){
            answer[y][x+i] = '*';
        }
        answer[y-1][x+1] = answer[y-1][x+3] = answer[y-2][x+2] = '*';
        return;
    }

    fill(k/2, x + k/2, y - k/2);
    fill(k/2, x, y);
    fill(k/2, x+k, y);
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i<n; i++){
        answer[i] = string(n*2, ' ');
    }

    fill(n, 0, n-1);

    for(int i = 0; i<n; i++){
        cout << answer[i] << '\n';
    }
}