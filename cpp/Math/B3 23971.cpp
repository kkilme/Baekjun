// 2024-12-24 ZOAC 4
// 수학
#include <iostream>

using namespace std;

int main(){
    int h,w,n,m;

    cin >> h >> w >> n >> m;

    cout << (((w-1)/(m+1)) + 1) * (((h-1)/(n+1)) + 1);
}