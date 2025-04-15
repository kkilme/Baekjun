// 2025-04-16 과일 탕후루
// 구현 / 투 포인터 / 브루트포스
#include <iostream>

using namespace std;

int n;
int arr[200000];
int used[10];
int cur;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if(n == 1){
        cout << 1; return 0;
    }
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    used[arr[0]]++; used[arr[1]]++;
    if(arr[0] == arr[1]) cur = 1; else cur = 2;

    int l = 0; int r = 1;
    int answer = 2;
    while(r < n-1){
        if(cur > 2){
            if(!--used[arr[l++]]) cur--;
        } else {
            if(!used[arr[++r]]++) cur++;
        }
        if(cur <= 2) answer = max(answer, r - l + 1);
    }

    cout << answer;
}