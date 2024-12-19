// 20241111 나무 자르기
// 이분탐색
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> trees;

    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        trees.push_back(k);
    }

    sort(trees.begin(), trees.end(), greater<int>());

    int h = trees[0], l=0;
    int mid;
    while(h>=l){
        mid = (h+l)/2;
        long long total = 0;
        for(int t: trees){
            if(t > mid) total += t - mid;
        }
        // cout << h << ' ' << mid << ' ' << l << ' ' << total << endl;
        if(total == m) break;
        else if(total > m){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    if(h<l){
        long long total = 0;
        for(int t: trees){
            if(t > mid) total += t - mid;
        }
        if(total < m) mid--;
    }
    cout << mid;
}