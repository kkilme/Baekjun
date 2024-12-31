// 2025-01-01 앵그리 창영
// 수학
#include <iostream>

using namespace std;

int main(){
    int n, w, h;
    cin >> n >> w >> h;

    while(n--){
        int k;
        cin >> k;
        if(k*k <= w*w + h*h) cout << "DA\n";
        else cout << "NE\n";
    }
}