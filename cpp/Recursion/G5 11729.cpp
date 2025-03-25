// 2025-03-24 하노이 탑 이동 순서
// 재귀
#include <iostream>
#include <math.h>
using namespace std;

int cnt;
void hanoi(int n, int from, int mid, int to){
    if(n == 1){
        cout << from << " " << to << "\n";
        cnt++;
    } else {
        hanoi(n - 1, from, to, mid);
        hanoi(1, from, mid, to);
        hanoi(n - 1, mid, from, to);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    cnt = 0;
    cout << fixed;
    cout.precision(0);
    cout << pow(2, n) - 1 << "\n";
    hanoi(n, 1, 2, 3);
}