// 2025-03-11 일곱 난쟁이
// 브루트포스 알고리즘 / 정렬
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int arr[9];
    for(int i = 0; i<9; i++){
        cin >> arr[i];
    }

    sort(arr, arr+9);

    for(int i = 0; i<9; i++){
        for(int j = i+1; j<9; j++){
            int sum = 0;
            for(int p = 0; p<9; p++){
                if(p == i || p == j) continue;
                sum += arr[p];
            }
            if(sum == 100){
                for(int p = 0; p<9; p++){
                    if(p == i || p == j) continue;
                    cout << arr[p] << '\n';
                }
                return 0;
            }
        }
    }

}