// 2024-12-21 부분합
// 투 포인터
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int p1 = 0, p2 = 0;
    int cursum = arr[0];
    int answer = cursum >= s ? 1 : 100001;
    while(p1 != n-1){
        if(cursum < s && p2 != n-1){
            cursum += arr[++p2];
        } else {
            cursum -= arr[p1++];
        }
        if(cursum >= s) answer = min(answer, p2-p1+1);
    }

    if (answer != 100001) cout << answer;
    else cout << 0;
}