// 2025-02-12 Four Squares
// 브루트포스 / DP?
#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int ans = 0;

    int cur = 0;
    int start = 223;
    
    if(pow((int)sqrt(n),2) == n){
        cout << 1; return 0;
    }

    for(int i = 223; i>0; i--){
        for(int j = i; j>0; j--){
            if(pow(i, 2) + pow(j, 2) == n){
                cout << 2; return 0;
            }
        }
    }

    for(int i = 223; i>0; i--){
        for(int j = i; j>0; j--){
            for(int k = j; k>0; k--){
                if(pow(i, 2) + pow(j, 2) + pow(k, 2) == n){
                    cout << 3; return 0;
                }
            }
        }
    }
    
    cout << 4;

}