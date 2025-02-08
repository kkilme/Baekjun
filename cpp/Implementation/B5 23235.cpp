// 2025-02-09 The Fastest Sorting Algorithm In The World
// 구현
#include <iostream>

using namespace std;
int arr[101];
int main(){

    int idx = 1;
    int n;
    while (true)
    {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        cout << "Case " << idx++ << ": Sorting... done!" << '\n';
    }
}