// 2025-03-13 한 줄로 서기
// 구현 / 그리디 알고리즘
#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[10];
    int sorted[10] = {0,};
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i<n; i++){
        int idx = arr[i];
        while(idx<n-1){
            if(sorted[idx]){
                idx++;
                continue;
            }
            int cnt = 0;
            for(int j = idx-1; j>=0; j--){
                if(!sorted[j]) cnt++;
            }
            if(cnt >= arr[i]) break;
            else idx++;
        }
        sorted[idx] = i+1;
    }

    for(int i = 0; i<n; i++){
        cout << sorted[i] << ' ';
    }
}