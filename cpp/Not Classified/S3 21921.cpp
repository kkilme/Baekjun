// 2025-03-01 블로그
// 누적 합 / 슬라이딩 윈도우
#include <iostream>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;

    cin >> n >> x;

    vector<int> v(n);

    for(int i = 0; i<n; i++){
        cin >> v[i];
    }

    int curmax = 0;
    int counts = 1;
    for(int i = 0; i<x; i++){
        curmax += v[i];
    }

    int l = 0, r = x-1;
    int cursum = curmax;
    while(r < n){
        cursum = cursum + v[++r] - v[l++];
        if(cursum > curmax){
            curmax = cursum;
            counts = 1;
        }
        else if(cursum == curmax){
            counts++;
        }
    }

    if(curmax == 0){
        cout << "SAD";
    }
    else{
        cout << curmax << '\n' << counts;
    }
}