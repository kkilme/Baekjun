// 2025-06-26 수열의 점수
// 그리디 알고리즘 / 정렬
// 1744와 거의 같은듯?
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[100000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n, [](ll a, ll b){return abs(a)>abs(b);});

    ll ans, neg , pos;
    ans = neg = pos = 0;
    bool haszero = false;
    for(int i = 0; i<n; i++){
        ll cur = arr[i];
        if(cur < 0){
            if(neg != 0){
                ans += cur * neg;
                neg = 0;
            } else {
                neg = cur;
            }
        } else if(cur > 0){
            if(cur == 1){
                ans += pos + 1;
                pos = 0;
            } else if(pos != 0){
                ans += cur * pos;
                pos = 0;
            } else {
                pos = cur;
            }
        } else {
            haszero = true;
        }
    }
    cout << ans + pos + (!haszero * neg);
}