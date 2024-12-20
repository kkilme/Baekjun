// 2024-12-21 오등큰수
// 자료구조 / 스택
// map: O(logN) / unordered_map: O(1)
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> inputs(n);
    vector<int> answer(n, -1);
    unordered_map<int, int> counts;
    
    for(int i = 0; i<n; i++){
        cin >> inputs[i];
        counts[inputs[i]]++;
    }

    stack<int> stack;

    for(int i = 0; i<inputs.size(); i++){
        while (!stack.empty() && counts[inputs[stack.top()]] < counts[inputs[i]]){
            answer[stack.top()] = inputs[i];
            stack.pop();
        }
        stack.push(i);
    }

    for(int i = 0; i<answer.size(); i++){
        cout << answer[i] << ' ';
    }
}