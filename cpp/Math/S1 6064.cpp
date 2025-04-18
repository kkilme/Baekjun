// 2025-04-18 카잉 달력
// 수학 / 브루트포스 / 정수론 / 중국인의 나머지 정리?
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int m,n,x,y;
        cin >> m >> n >> x >> y;
        int lcm = m * n / gcd(m, n);
        int next = x;
        bool flag = false;
        while(next <= lcm){
            if((next - y)%n == 0){
                cout << next << '\n';
                flag = true;
                break;
            }
            next += m;
        }
        if(!flag) {
            cout << -1 << '\n';
        }
    }
}