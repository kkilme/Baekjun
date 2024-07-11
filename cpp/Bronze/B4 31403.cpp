// B4 31403 A + B - C

#include <iostream>
#include <string>
using namespace std;

int main(){

    string a, b;
    int c;

    cin >> a >> b >> c;
    cout << stoi(a) + stoi(b) - c << endl;
    cout << stoi(a + b) - c;
}
