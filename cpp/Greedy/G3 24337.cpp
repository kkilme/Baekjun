// 2025-02-17 가희와 탑
// 그리디 알고리즘 / 해 구성하기
#include <iostream>

using namespace std;

int n, a, b;
int buil[100000];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;

    if(a + b > n + 1){
        cout << -1;
        return 0;
    }

    for(int i = 0; i<=n-b-a+1; i++){
        buil[i] = 1;
    }

    int k = 2;
    for(int i = n-b-a+2; i<=n-b; i++){
        buil[i] = k++;
    }
    k = 1;
    for(int i = n-1; i >= n-b+1; i--){
        buil[i] = k++;
    }
    if(a<b && a!=1) buil[n-b] = k;
    else if(a == 1) buil[0] = k;

    for(int i = 0; i<n; i++){
        cout << buil[i] << ' ';
    }
}