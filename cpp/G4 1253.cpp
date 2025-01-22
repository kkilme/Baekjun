// 2025-01-22 좋다
// 자료 구조? / 정렬 / 이분 탐색? / 투 포인터
#include <iostream>
#include <algorithm>

using namespace std;

int arr[2001];
int answer = 0;
int n;
void solve(int a, int idx){
    int l = 0;
    int r = n-1;
    while(l<r){
        if (l == idx) {
            l++;
            continue;
        }
        if (r == idx) {
            r--;
            continue;
        }
        if(arr[l] + arr[r] == a){
            answer++;
            break;
        }
        if(arr[l] + arr[r] < a){
            l++;
        }else{
            r--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    for(int i = 0; i<n; i++){
        solve(arr[i], i);
    }
    cout << answer;
}