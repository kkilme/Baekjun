// 2025-07-01 소수의 연속합
// 수학 / 정수론 / 투 포인터 / 소수 판정 / 에라토스테네스의 체
#include <bits/stdc++.h>
using namespace std;

bool notPrime[4000002];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    vector<int> primes;

    for(long long i = 2; i<=n; i++){
        if(notPrime[i]) continue;
        primes.push_back(i);
        for(long long j = i*i; j<=n; j+=i){
            notPrime[j] = true;
        }
    }

    int ans = 0;
    int cur = primes[0];
    int l = 0, r = 0;
    while(l<=r){
        if(cur == n){
            ans++;
        }
        if(cur <= n && primes[r] < n && r<primes.size()){
            cur += primes[++r];
        } else {
            cur -= primes[l++];
        }
    }

    cout << ans;
}