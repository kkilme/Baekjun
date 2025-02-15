// 2025-02-15 줄세우기
// 구현 / 정렬 / 시뮬레이션
#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[20];

        for(int i = 0; i<20; i++){
            cin >> arr[i];
        }

        int count = 0;
        for(int i = 0; i<20; i++){
            for(int j = 0; j<i; j++){
                if(arr[i] < arr[j]) count++;
            }
        }
        cout << n << ' ' << count << '\n';
    }
    
}