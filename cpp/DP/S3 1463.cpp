// 2024-11-02 1로 만들기
// DP

#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n;
    int *m = new int[1000001];

    cin >> n;

    m[1] = 0; m[2] = 1; m[3] = 1;
    for(int i = 4; i<1000001; i++){
        if(i%6 == 0) m [i] = min({m[i/3], m[i/2], m[i-1]}) + 1;
        else if(i%3 == 0) m[i] = min(m[i/3], m[i-1]) + 1;
        else if(i%2 == 0) m[i] = min(m[i/2], m[i-1]) + 1;
        else m[i] = m[i-1] + 1;
    }
    cout << m[n];
}

// 0 1 1 2 3 2 3 3 2 3 / 4 3 4 4 4 4 5 3 4 