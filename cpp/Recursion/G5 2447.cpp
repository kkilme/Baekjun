// 2025-03-26 별 찍기 - 10
// 분할 정복 / 재귀
#include <iostream>
#include <string>
using namespace std;

int n;
string answer[7000];
void draw(int k, int x, int y){
    if(k == 1){
        answer[y][x] = '*';
        return;
    }
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(i == 1 && j == 1) continue;
            draw(k/3, x + k/3 * i, y + k/3 * j);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        answer[i] = string(n, ' ');
    }
    draw(n, 0, 0);
    for(int i = 0; i < n; i++){
        cout << answer[i] << '\n';
    }
}