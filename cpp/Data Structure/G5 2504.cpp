// 2025-04-12 괄호의 값
// 구현 / 자료구조 / 스택
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

string s;
int depth;
vector<vector<int>> sums(31, vector<int>());
stack<char> st;

bool closebracket(char check, int num){
    if(st.empty() || st.top() != check){
        return false;
    }
    st.pop();
    if(sums[depth].empty()){
        sums[depth-1].push_back(num);
    } else {
        int sum = 0;
        for(int i : sums[depth]){
            sum += i;
        }
        sums[depth].clear();
        sums[depth-1].push_back(sum * num);
    }
    depth--;
    return true;
}

int main(){   
    cin >> s;
    depth = 0;
    for(char c : s){
        if(c == ')'){
            if(!closebracket('(', 2)){
                cout << 0;
                return 0;
            }
        } else if(c == ']'){
            if(!closebracket('[', 3)){
                cout << 0;
                return 0;
            }
        } else if(c == '(' || c == '['){
            depth++;
            st.push(c);
        }
    }

    if(!st.empty()){
        cout << 0;
        return 0;
    }
    int sum = 0;
    for(int i : sums[0]){
        sum += i;
    }
    cout << sum;

}