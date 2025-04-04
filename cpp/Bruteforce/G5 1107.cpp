// 2025-04-05 리모컨
// 브루트포스
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int n;
bool nums[10];
int answer = 500000;
void solve(int depth, int num, int size){
    if(depth == 0){
        if(!nums[0] && num == 0) return;
        answer = min(answer, abs(n - num) + size);
        return;
    }
    for(int i = 0; i < 10; i++){
        if(!nums[i] && !(i == 0 && size == 1)) continue;
        solve(depth - 1, i * pow(10, depth - 1) + num, i != 0 && size == 1 ? depth : size);
    }
}

int main(){

    string sn;
    cin >> sn;
    n = stoi(sn);
    int m;
    cin >> m;
    fill(nums, nums + 10, true);
    if(m == 0){
        cout << min((int)sn.size(), abs(n - 100));
        return 0;
    } else if (m == 10) {
        cout << abs(n - 100);
        return 0;
    }

    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        nums[a] = false;
    }
    solve(sn.size()+1, 0, 1);
    cout << min(answer, abs(n - 100));
}