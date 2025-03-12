// 2025-03-13 주식
// 그리디 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int price[1000000];
int benefit[1000000];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        fill(price, price+n, 0);
        fill(benefit, benefit+n, -1);
        vector<pair<int, int>> v;
        for(int i = 0; i<n; i++){
            int p;
            cin >> p;
            price[i] = p;
            v.push_back({p, i});
        }
        sort(v.begin(), v.end(), greater<>());
        
        int cur = -1;
        int prv = -1;

        for(int i = 0; i<n; i++){
            auto p = v[i];
            if(prv == p.first || cur > p.second) continue;
            prv = p.first;
            cur = p.second;
            for(int j = p.second-1; j>=0; j--){
                if(price[j] < p.first) benefit[j] = max(benefit[j], p.first);
            }
        }

        long long ans = 0;
        for(int i = 0; i<n; i++){
            if(benefit[i] != -1){
                ans += benefit[i] - price[i];
            }
        }

        cout << ans << '\n';
    }
    
}

/* 더 좋은 코드 O(n)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> prices(n);
        for (int i = 0; i < n; i++){
            cin >> prices[i];
        }
        
        long long maxPrice = 0;
        long long profit = 0;

        for (int i = n - 1; i >= 0; i--){
            if(prices[i] > maxPrice){
                maxPrice = prices[i];
            } else {
                profit += (maxPrice - prices[i]);
            }
        }
        
        cout << profit << "\n";
    }
    
    return 0;
}
*/