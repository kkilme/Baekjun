// 2025-07-12 Metronome
// 수학 / 사칙연산
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n % 2 == 0) cout << fixed << setprecision(1) << n / 4.0;
    else cout << fixed << setprecision(2) << n / 4.0;
}