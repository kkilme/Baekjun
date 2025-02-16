// 2025-02-16 등수 구하기
// 구현
#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, score, p;
    int arr[50];

    cin >> n >> score >> p;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    if(n >= p && arr[n-1] >= score){
        cout << -1;
        return 0;
    } else if (n < p && arr[n-1] > score){
        cout << n+1;
        return 0;
    }
    int rank = 1;
    int prev = -1;
    for(int i = 0; i<n; i++){
        if(score >= arr[i]) {
            if(arr[i] != prev) rank = i+1;
            break;
        }
        if(arr[i] != prev){
            rank = i+2;
        }
        prev = arr[i];
    }
    if(rank <= p) cout << rank;
    else cout << -1;
}