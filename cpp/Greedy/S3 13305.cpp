// 2025-02-28 주유소
// 그리디
#include <iostream>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> dists(n-1);
    vector<long long> cost(n);

    for(int i = 0; i<n-1; i++){
        cin >> dists[i];
    }

    for(int i = 0; i<n; i++){
        cin >> cost[i];
    }

    int cur = 0;
    long long answer = 0;
    while(cur < n-1){
        int i = cur+1;
        while(i < n && (cost[cur] <= cost[i])){
            answer += cost[cur] * dists[i-1];
            i++;
        }
        if(i<n) answer += cost[cur] * dists[i-1];
        cur = i;
    }

    cout << answer;
}