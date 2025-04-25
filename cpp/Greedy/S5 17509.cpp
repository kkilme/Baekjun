// 2025-04-25 And the Winner Is... Ourselves!
// 그리디 / 정렬
#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[11];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i<11; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr+11);

    int cur = 0;
    int ans = 0;
    for(int i = 0; i<11; i++){
        cur += arr[i].first;
        ans += cur + arr[i].second * 20;
    }
    cout << ans;
}