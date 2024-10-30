#include <iostream>
#include <random>
using namespace std;

int main(){

    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> d(1, 100); // 1~100

    int a = d(gen);
}