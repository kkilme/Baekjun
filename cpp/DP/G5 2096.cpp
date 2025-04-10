// 2025-04-11 내려가기
// DP / 슬라이딩 윈도우?
#include <iostream>

using namespace std;

int mn[3];
int mx[3];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;
    mn[0] = mx[0] = a;
    mn[1] = mx[1] = b;
    mn[2] = mx[2] = c;
    for(int i = 1; i<n; i++){
        cin >> a >> b >> c;
        int temp[3] = {mn[0], mn[1], mn[2]};
        mn[0] = min(temp[0], temp[1]) + a;
        mn[1] = min(temp[0], min(temp[1], temp[2])) + b;
        mn[2] = min(temp[1], temp[2]) + c;
        int temp2[3] = {mx[0], mx[1], mx[2]};
        mx[0] = max(temp2[0], temp2[1]) + a;
        mx[1] = max(temp2[0], max(temp2[1], temp2[2])) + b;
        mx[2] = max(temp2[1], temp2[2]) + c;
    }

    cout << max(mx[0], max(mx[1], mx[2])) << " " << min(mn[0], min(mn[1], mn[2]));

}