// 2025-03-06 좌표 압축
// 정렬 / 값 or 좌표 압축
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[1000001];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr, arr + n);

    int prev = arr[0].first;
    int pstart = 0;
    for (int i = 0; i < n; i++) {
        int temp = arr[i].second;
        if(arr[i].first != prev){
            prev = arr[i].first;
            arr[i].second = ++pstart;
            arr[i].first = temp;
        } else {
            prev = arr[i].first;
            arr[i].second = pstart;
            arr[i].first = temp;
        }
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i].second << ' ';
    }
}