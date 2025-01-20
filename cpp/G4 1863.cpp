// 2025-01-21 스카이라인 쉬운거
// 자료구조 / 스택
#include <iostream>
#include <stack>

using namespace std;

int pos[50001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        int x, y;
        cin >> x >> y;
        pos[i] = y;
    }

    int answer = 0;

    stack<int> s;
    
    for(int i = 0; i<n; i++){
        if(s.empty() && pos[i] != 0){
            s.push(pos[i]);
            answer++;
            continue;
        }
        if(!s.empty() && s.top() < pos[i]){
            answer++;
            s.push(pos[i]);
        } else {
            while(!s.empty() && s.top() > pos[i]){
                s.pop();
            }
            if(!s.empty() && s.top() == pos[i]) continue;
            if(pos[i] != 0){
                answer++;
                s.push(pos[i]);
            }
        }
    }
    cout << answer;
}

// 개선 코드(from gpt)
//     for (int i = 0; i<n; i++) {
//         while (!s.empty() && s.top() > pos[i]) {
//             s.pop();  // 현재 높이보다 높은 건물은 pop
//         }

//         if (!s.empty() && s.top() == pos[i]) {
//             continue;  // 같은 높이라면 추가하지 않음
//         }

//         if (pos[i] != 0) {
//             s.push(pos[i]);
//             answer++;
//         }
//     }
