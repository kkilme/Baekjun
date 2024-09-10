#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int D, H, W, h, w;
    float k;

    cin >> D >> H >> W;
    k = sqrt(pow(D,2)/(pow(H,2)+pow(W,2)));
    h = floor(H*k);
    w = floor(W*k);

    cout << h << " " << w << endl;

}