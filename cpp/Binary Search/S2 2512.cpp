// 2025-02-15 예산
// 이분 탐색 / 매개 변수 탐색?
#include <iostream>
#include <algorithm>

using namespace std;

int request[10000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int sum = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> request[i];
        sum += request[i];
    }

    cin >> m;

    if(sum <= m){
        cout << *max_element(request, request + n);
        return 0;
    }
    int l = 0; int h = m;
    
    while(l<=h){
        int mid = (l+h)/2;
        int cur = 0;
        for(int i = 0; i<n; i++){
            cur += min(request[i], mid);
        }
        if(cur == m){
            cout << mid;
            return 0;
        }
        if(cur < m)l = mid + 1; 
        else h = mid - 1;
    }

    cout << h;

}