// 2025-06-05 가장 긴 증가하는 부분 수열 4
// DP / 역추적
// 풀긴 했는데 중요해보여서 느낌표 달아둠
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000];
int dp[1000];
int track[1000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[j] < arr[i]){
                if(dp[i] < dp[j]+1){
                    track[i] = j;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    auto it = max_element(dp, dp+n);
    cout << *it << '\n';
    
    vector<int> p;
    auto k = distance(dp, it);
    int j = k;

    for(int i = 0; i<dp[k]; i++){
        p.push_back(arr[j]);
        j = track[j];
    }

    reverse(p.begin(), p.end());

    for(int i = 0; i<p.size(); i++){
        cout << p[i] << ' ';
    }

}