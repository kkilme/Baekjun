// 2025-02-01 줄세우기
// 다이나믹 프로그래밍
// LIS 구하기: Longest Increasing Subsequence
// 아이디어를 못떠올림
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    int arr[200];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int count[200] = {0,};

    for(int i = n-1; i>=0; i--){
        int mx = 0;
        for(int j = i+1; j<n; j++){
            if(arr[i] < arr[j]){
                mx = max(mx, count[j]);
            }
        }
        count[i] = mx+1;
    }

    cout << n - *max_element(count, count+n);
}