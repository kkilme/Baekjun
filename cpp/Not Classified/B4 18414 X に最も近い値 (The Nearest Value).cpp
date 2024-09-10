#include <iostream>

using namespace std;

int main(){

    int x, l, r;

    cin >> x >> l >> r;

    if (l<=x && x<=r){
        cout << x;
    }
    else if (x>r){
        cout << r;
    }
    else if (x<l){
        cout << l;
    }
    
}