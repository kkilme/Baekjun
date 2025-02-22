// 2025-02-23 스위치 켜고 끄기
// 구현 / 시뮬레이션
#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int arr[101];
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;
    for(int i = 0; i<k; i++){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            for(int j = 1; j<=n; j++){
                if(j%b == 0){
                    arr[j] = !arr[j];
                }
            }
        } else if(a == 2) {
            int l = b, r = b;
            arr[b] = !arr[b];
            while(l > 0 && r <= n){
                if(arr[l] == arr[r]){
                    arr[l] = !arr[l];
                    arr[r] = !arr[r];
                    l--;
                    r++;
                } else {
                    break;
                }
            }
        }
    }

    int i = 1;
    while(i <= n){
        cout << arr[i] << ' ';
        i++;
        if(i%20 == 1){
            cout << '\n';
        }
    }
}