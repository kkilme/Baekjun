// 2024-09-16 814 - 1
// 기하학, 해 구성하기, 무작위화

#include <iostream>
#include <random>
using namespace std;

int main(){

    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> d(-8140, 8140);

    for(int i = 0; i <814; i++){
        int a, b;
        a = d(gen);
        b = d(gen);

        cout << a << ' ' << b << '\n';
    }

}