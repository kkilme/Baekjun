// 2025-02-04 팩토리얼
// 수학 / 구현

#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    long long answer = 1;
    for(int i = 1; i<=n; i++){
        answer *= i;
    }
    cout << answer;

}