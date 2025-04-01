// 2025-04-02 Fly me to the Alpha Centauri
// 수학
// 그냥 수학 규칙 찾기 문제...
// d = 1부터 차례대로 구해봤으면 규칙이 보였을지도
// 근데 공식을 구하진 못했을듯
#include <iostream>
#include <cmath>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int d = y - x;
        int n = sqrt(d);
        if(n*n == d){
            cout << 2*n-1 << "\n";
        } else if(d <= n*(n+1)){
            cout << 2*n << "\n";
        } else {
            cout << 2*n+1 << "\n";
        }
    }
}

/*
***
d = n^2 -> 2n-1
n^2 < d <= n(n+1) -> 2n
n(n+1) < d < (n+1)^2 -> 2n+1
***
d = 1 -> 1
1
d = 2 -> 2
1 1
d = 3 -> 3
1 1 1
d = 4 -> 3
1 2 1
d = 5 -> 4
1 2 1 1
d = 6 -> 4
1 2 2 1
d = 7 -> 5
1 2 2 1 1
d = 8 -> 5
1 2 2 2 1
d = 9 -> 5
1 2 3 2 1
d = 10 -> 6
1 2 3 2 1 1
d = 11 -> 6
1 2 2 3 2 1
d = 12 -> 6
1 2 3 3 2 1
d = 13 -> 7
1 2 3 3 2 1 1
d = 14 -> 7
d = 15 -> 7
d = 16 -> 7
1 2 3 4 3 2 1
d = 17 -> 8
*/