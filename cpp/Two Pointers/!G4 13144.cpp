// 2025-01-26 List of Unique Numbers
// 백트래킹: 시간초과
// 투 포인터
#include <iostream>
#include <unordered_set>

using namespace std;

int n;
int arr[100001];
long long answer = 0;
unordered_set<int> s;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int l = 0, r = 0;

    while(r<n){
        if(s.find(arr[r]) == s.end()){
            s.insert(arr[r++]);
            answer += r-l;
        } else {
            s.erase(arr[l++]);
        }
    }

    cout << answer;
}