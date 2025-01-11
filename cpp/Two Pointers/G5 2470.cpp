// 2025-01-12 두 용액
// 투 포인터 / 이분 탐색? / 정렬?
// 2467과 정렬 빼고 동일
#include <iostream>
#include <algorithm>
int arr[100000];
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);    

    long long cur, cursum;
    int answer1, answer2;
    cur = cursum = arr[0] + arr[n-1];
    answer1 = arr[0];
    answer2 = arr[n-1];

    int l, r;
    l = 0; r = n-1;

    while(l < r){
        if(abs(cur) < abs(cursum)){
            cursum = cur;
            answer1 = arr[l]; answer2 = arr[r];
            if(cursum == 0) break;
        }
        if(r-l > 1 && (abs(arr[r-1] + arr[l]) < abs(arr[r] + arr[l+1]))){
            cur -= arr[r];
            cur += arr[--r];
        } else {
            cur -= arr[l];
            cur += arr[++l];
        }
    }

    cout << answer1 << ' ' << answer2;
}