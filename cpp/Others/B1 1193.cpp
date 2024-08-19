#include <iostream>
using namespace std;

int main(){

    int x;
    int up, down;
    int n = 0;
    int count = 1;
    cin >> x;

    while(n + count < x){ // x=4 n=3 count=3 , x=14 n=10 count=5
        n+=count;
        count++;
    }
    if(count % 2 == 0){
            down = count - (x - n) + 1;
            up = x - n;
    } else {
        down = x - n;
        up = count - (x - n) + 1;
    }
    cout << up << "/" << down;
}