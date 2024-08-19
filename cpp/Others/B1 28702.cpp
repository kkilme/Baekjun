// FizzBuzz
# include <iostream>
# include <string>
using namespace std;

bool isNum(const string& str){
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main(){
    string a;

    for(int i = 3; i > 0; i--){
        cin >> a;
        if(isNum(a)){
            int answer = stoi(a) + i;
            if (answer % 15 == 0) cout << "FizzBuzz";
            else if (answer % 5 == 0) cout << "Buzz";
            else if (answer % 3 == 0) cout << "Fizz";
            else cout << answer;
            break;
        }
    }
}