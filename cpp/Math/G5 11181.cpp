// 2025-04-03 Base-2 Palindromes
// 수학? / 조합론?
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

pair<int, pair<int, string>> arr[50001];
int base[4] = {1, 3, 5, 7};
int main(){

    int up = 1;
    int i = 5;
    while(i < 50001){
        for(int j = 0; j < pow(2, up) && i < 50001; j++){
            arr[i++] = {j, {up, ""}};
        }
        for(int j = 0; j < pow(2, up) && i < 50001; j++){
            arr[i++] = {j, {up, "0"}};
            if(i == 50001) break;
            arr[i++] = {j, {up, "1"}};
        }
        up++;
    }
    int m;
    cin >> m;
    if(m < 5) cout << base[m-1];
    else{
        int a = arr[m].first;
        string binary = "";
        while (a > 0) {
            binary = to_string(a % 2) + binary;
            a /= 2;
        }
        for(int j = binary.length(); j<arr[m].second.first; j++){
            binary = "0" + binary;
        }
        binary = "1" + binary;
        string rv = binary;
        reverse(rv.begin(), rv.end());
        binary = binary + arr[m].second.second + rv;
        cout << stoi(binary, nullptr, 2);
    }
}