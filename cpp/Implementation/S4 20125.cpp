// 2025-02-11 쿠키의 신체 측정
// 구현
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<string> pic(n);

    for(int i = 0; i<n; i++){
        cin >> pic[i];
    }

    int x, y;
    bool found = false;
    for(int i = 0; i<n && !found; i++){
        for(int j = 0; j<n && !found; j++){
            if(i-1 >= 0 && pic[i][j] == '*' && pic[i-1][j] == '*'){
                x = i+1; y = j+1;
                found = true;
                break;
            }
        }
    }

    int a, b, c, d, e;
    a = b = c = d = e = 0;

    for(int i = y-2; i>=0; i--){
        if(pic[x-1][i] == '*') a++;
        else break;
    }

    for(int i = y; i<n; i++){
        if(pic[x-1][i] == '*') b++;
        else break;
    }

    for(int i = x; i<n; i++){
        if(pic[i][y-1] == '*') c++;
        else break;
    }

    for(int i = x+c; i<n; i++){
        if(pic[i][y-2] == '*') d++;
        else break;
    }

    for(int i = x+c; i<n; i++){
        if(pic[i][y] == '*') e++;
        else break;
    }

    cout << x << ' ' << y << '\n' << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e;
}