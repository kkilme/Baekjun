// 잃어버린 괄호
// 문자열

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, cur;
    string num = "";
    int sum = 0, temp=0;
    
    cin >> s;

    for(int i = s.length()-1; i>=0; i--){
        cur = s[i];
        // cout << cur << " " << num << " " << sum << endl;
        if(cur.compare("-") == 0){
            reverse(num.begin(), num.end());
            temp += stoi(num);
            sum -= temp;
            temp = 0;
            num = "";

        } else if (cur.compare("+") == 0){
            reverse(num.begin(), num.end());
            temp += stoi(num);
            num = "";
        } else {
            num.append(cur);
        }
    }
    reverse(num.begin(), num.end());
    sum += stoi(num) + temp;

    cout << sum;
}