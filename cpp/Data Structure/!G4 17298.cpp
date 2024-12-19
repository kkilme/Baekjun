// 2024-12-19 오큰수
// 자료구조 / 스택
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> inputs;
    vector<int> answer(n, -1);
    while(n--){
        int k;
        cin >> k;
        inputs.push_back(k);
    }
    
    vector<int> stack;

    for(int i = 0; i<inputs.size(); i++){
        while (!stack.empty() && inputs[stack.back()] < inputs[i]){
            int k = stack.back();
            stack.pop_back();
            answer[k] = inputs[i];
        }
        stack.push_back(i);
    }

    for(int i = 0; i<answer.size(); i++){
        cout << answer[i] << ' ';
    }
}