// 2025-01-16 0 만들기
// 구현 / 문자열 / 브루트포스 / 백트래킹?
#include <iostream>
#include <string>
using namespace std;

int t, n;

void find(int num, char op, int prev, int result, string s){
    if(op == '+'){
        result += num;
        s += '+' + to_string(num);
        prev = num;
    } else if (op == '-'){
        result -= num;
        s += '-' + to_string(num);
        prev = -num;
    } else if (op == ' '){
        result -= prev;
        s += ' ' + to_string(num);
        if(prev < 0) {
            result += prev * 10 - num;
            prev = prev * 10 - num;
        }
        else{
            result += prev * 10 + num;
            prev = prev * 10 + num;
        }
    }

    if(num == n){
        if(result == 0){
            cout << s << '\n';
        }
        return;
    }

    find(num + 1, ' ', prev, result, s);
    find(num + 1, '+', prev, result, s);
    find(num + 1, '-', prev, result, s);

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        
        find(2, ' ', 1, 1, "1");
        find(2, '+', 1, 1, "1");
        find(2, '-', 1, 1, "1");

        cout << '\n';
    }
}