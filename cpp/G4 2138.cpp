// 2025-01-19 전구와 스위치
// 그리디 알고리즘
#include <iostream>
#include <string>
using namespace std;

int n;
string goal;
string cur_original;

int solve(string cur, bool first_pushed){
    int ans = 0;
    if(first_pushed) ans++;

    for(int i = 1; i<n-1; i++){
        if(cur[i-1] != goal[i-1]){
            cur[i-1] = goal[i-1];
            cur[i] = cur[i] == '1' ? '0' : '1';
            cur[i+1] = cur[i+1] == '1' ? '0' : '1';
            ans++;
        }
    }

    if(cur[n-2] != goal[n-2]){
        cur[n-2] = goal[n-2];
        cur[n-1] = cur[n-1] == '1' ? '0' : '1';
        ans++;
    }

    if(cur[n-1] != goal[n-1]){
        return 2e9;
    } else return ans;
}

int main(){
    cin >> n >> cur_original >> goal;
    int ans1, ans2;
    ans1 = solve(cur_original, false);
    cur_original[0] = cur_original[0] == '1' ? '0' : '1';
    cur_original[1] = cur_original[1] == '1' ? '0' : '1';
    ans2 = solve(cur_original, true);

    int ans = min(ans1, ans2);

    if(ans == 2e9) cout << -1;
    else cout << ans;
}