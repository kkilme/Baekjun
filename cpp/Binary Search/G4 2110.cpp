// 2025-01-24 공유기 설치
// 이분 탐색 / 매개 변수 탐색?
#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int house[200000];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    for(int i = 0; i<n; i++){
        cin >> house[i];
    }

    sort(house, house+n);

    int mn = 1;
    int mx = house[n-1] - house[0];

    while(mn<=mx){
        int mid = (mx+mn)/2;
        int cnt = 1;
        int prev = house[0];
        for(int i = 1; i<n; i++){
            if(house[i] - prev >= mid){
                cnt++;
                prev = house[i];
            }
        }
        if(cnt >= c){
            mn = mid + 1;
        }else{
            mx = mid - 1;
        }
    }

    cout << mx;
}