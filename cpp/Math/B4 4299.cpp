// 2024-09-02 AFC 윔블던

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int a, b, n, m;

    cin >> a >> b;

    if ((a + b) % 2 == 1) cout << -1;
    else{

        n = (a + b) / 2;
        m = (a - b) / 2;
        if (n < 0 || m < 0) cout << -1;
        else cout << max(m, n) << ' ' << min(m, n);
    }
}