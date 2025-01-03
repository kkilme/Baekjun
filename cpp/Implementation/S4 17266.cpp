// 2025-01-04 어두운 굴다리
// 구현 / 이분탐색?
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int arr[100000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i<m; i++){
        cin >> arr[i];
    }

    int mx,prev;
    mx = prev = arr[0];

    for(int i = 1; i<m; i++){
        int dist = arr[i]-prev;
        if(dist % 2 == 0) dist /= 2;
        else dist = dist/2 + 1;

        mx = max(mx, dist);
        prev = arr[i];
    }

    cout << max(mx, n-arr[m-1]);
}