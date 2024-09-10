// 웰컴 키트
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int N, T, P, sum1 = 0, sum2;
    int arr[6];
    cin >> N;

    for(int i = 0; i<6; i++){
        cin >> arr[i];
    }

    cin >> T >> P;

    for(const int n: arr){
        sum1 += n / T;
        if(n%T != 0) sum1+=1;
    }

    cout << sum1 << endl;
    cout << N / P << " " << N % P;
}