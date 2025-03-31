// 2025-04-01 AC
// 구현 / 자료 구조? / 문자열 / 파싱 / 덱?
#include <iostream>
#include <string>
using namespace std;

int arr[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string command, raw;
        int n;
        fill(arr, arr+100001, 0);
        cin >> command >> n >> raw;
        string next = "";
        int idx = 0;
        for(int i = 1; ;i++){
            char c = raw[i];
            if(c == ']') {
                if(next != "") arr[idx++] = stoi(next);
                break;
            }
            if(c == ','){
                arr[idx++] = stoi(next);
                next = "";
            } else {
                next += c;
            }
        }
        int cur = n;
        int l = 0, r = n-1;
        bool isReverse = false;
        for(char c : command){
            if(c == 'R'){
                isReverse = !isReverse;
            } else {
                cur--;
                if(isReverse){
                    r--;
                } else {
                    l++;
                }
            }
        }
        if(l > r + 1){
            cout << "error\n";
            continue;
        }
        if(cur == 0){
            cout << "[]\n";
            continue;
        }
        cout << "[";
        if(isReverse){
            for(int i = r; i > l; i--){
                cout << arr[i] << ",";
            }
            cout << arr[l];

        } else {
            for(int i = l; i < r; i++){
                cout << arr[i] << ",";
            }
            cout << arr[r];
        }
        cout << "]\n";
    }
}