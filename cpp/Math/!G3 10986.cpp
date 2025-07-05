// 2025-07-05 나머지 합
// 수학 / 누적합
// 구간(i, j)가 M으로 나누어 떨어진다 <=> i까지 합의 나머지 = j까지 합의 나머지
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll cnt[1001]; // 나머지별로 구간 개수를 셈. cnt[i]: "현재까지 본 접두합 중, 나머지가 i인 것의 갯수".

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    ll sum = 0;
    cnt[0] = 1; // 중요

    for(int i = 0; i<n; i++){
        ll a;
        cin >> a;
        sum += a;
        sum %= m;
        cnt[sum]++;
    }

    ll ans = 0;
    for(int i = 0; i<m; i++){
        ans += (cnt[i] * (cnt[i] - 1)) / 2; // 센 카운트에서 2개를 뽑는 경우의 수 => cnt C 2
    }

    cout << ans;
}