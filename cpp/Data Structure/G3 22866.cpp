// 2025-02-13 탑 보기
// 자료구조 / 스택
#include <iostream>
#include <stack>
using namespace std;

int buildings[100001];
int counts[100001];
int closest[100001];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> buildings[i];
        closest[i] = -1;
    }

    stack<int> s;

    for(int i = 0; i<n; i++){
        while(!s.empty() && buildings[s.top()] <= buildings[i]){
            s.pop();
        }
        if(!s.empty()){
            counts[i] = s.size();
            closest[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for(int i = n-1; i>=0; i--){
        while(!s.empty() && buildings[s.top()] <= buildings[i]){
            s.pop();
        }
        if(!s.empty()){
            counts[i] += s.size();
            if(closest[i] == -1 || abs(s.top() - i) < abs(closest[i] - i)) closest[i] = s.top();
        }
        s.push(i);
    }


    for(int i = 0; i<n; i++){
        cout << counts[i];
        if(counts[i] != 0) cout << ' ' << closest[i] + 1;
        cout << '\n';
    }
}